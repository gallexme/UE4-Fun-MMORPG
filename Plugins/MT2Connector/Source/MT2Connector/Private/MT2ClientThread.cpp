#include "MT2ConnectorPrivatePCH.h"
#include "MT2Connector.h"
#include "MT2ClientThread.h"

//***********************************************************
//Thread Worker Starts as NULL, prior to being instanced
//		This line is essential! Compiler error without it
FMT2ClientThread* FMT2ClientThread::Runnable = NULL;
//***********************************************************

FMT2ClientThread::FMT2ClientThread(FString AuthIP,uint16 AuthPort, FString ChannelIP, uint16 ChannelPort,  AMT2Connector* mt2Connector)
	: Client(mt2Connector),
	 authIP(AuthIP),
	 authPort(AuthPort),
	 channelIP(ChannelIP),
	 channelPort(ChannelPort)
	
{
	
	const bool bAutoDeleteSelf = false;
	const bool bAutoDeleteRunnable = false;
	Thread = FRunnableThread::Create(this, TEXT("FMT2ClientThread"), bAutoDeleteSelf, bAutoDeleteRunnable, 0, TPri_BelowNormal); //windows default = 8mb for thread, could specify more
}

FMT2ClientThread::~FMT2ClientThread()
{
	delete Thread;
	Thread = NULL;
}

//Init
bool FMT2ClientThread::Init()
{

	if (Client)
	{
		Client->Log("**********************************");
		Client->Log("Client Thread Started!");
		Client->Log("**********************************");
	}
	return true;
}

//Run
uint32 FMT2ClientThread::Run()
{
	//Initial wait before starting
	FPlatformProcess::Sleep(0.03);
	std::string AuthIPString(TCHAR_TO_UTF8(*authIP));
	std::string ChannelIPString(TCHAR_TO_UTF8(*channelIP));
	TcpClient client(this,AuthIPString, authPort,
		ChannelIPString, channelPort);
	Logger::getInstance()->setDebugMode(true);
	TCPClient = &client;
	isRunning = true;
	
	//While not told to stop this thread 
	//		and not yet finished finding Prime Numbers
	while (!IsFinished())
	{
		if (!TCPClient->read()) {
			isRunning = false;
		}
	}

	//Run FPrimeNumberWorker::Shutdown() from the timer in Game Thread that is watching
	//to see when FPrimeNumberWorker::IsThreadFinished()

	return 0;
}

//stop
void FMT2ClientThread::Stop()
{
	if (TCPClient) {
		delete TCPClient;
		TCPClient = NULL;
	}
	StopTaskCounter.Increment();
}

FMT2ClientThread* FMT2ClientThread::JoyInit(FString AuthIP, uint16 AuthPort, FString ChannelIP, uint16 ChannelPort, AMT2Connector* mt2Connector)
{
	//Create new instance of thread if it does not exist
	//		and the platform supports multi threading!
	if (!Runnable && FPlatformProcess::SupportsMultithreading()){
		
		Runnable = new FMT2ClientThread( AuthIP,  AuthPort,  ChannelIP,  ChannelPort,  mt2Connector);
	}
	return Runnable;
}

void FMT2ClientThread::EnsureCompletion()
{
	Stop();
	Thread->WaitForCompletion();
}

void FMT2ClientThread::Shutdown()
{
	if (Runnable)
	{
		Runnable->EnsureCompletion();
		delete Runnable;
		Runnable = NULL;
	}
}

bool FMT2ClientThread::IsThreadFinished()
{
	if (Runnable) return Runnable->IsFinished();
	return true;
}

void FMT2ClientThread::send(void* data, uint32 length)
{
	
	if (Runnable)
	{
		Runnable->TCPClient->send(data, length);
		
	}
}
void FMT2ClientThread::changePhase(int32 phase) {
	Client->OnChangePhase(phase);
}
void FMT2ClientThread::callListenerFunction(uint8 oldHeader, void* packet)
{
	Client->OnPacket(oldHeader, packet);
}
void  FMT2ClientThread::connect(FString ip, uint16 port) {
	
	if (Runnable)
	{
		std::string ChannelIPString(TCHAR_TO_UTF8(*ip));
		Runnable->TCPClient->connect(ChannelIPString, port);

	}
}