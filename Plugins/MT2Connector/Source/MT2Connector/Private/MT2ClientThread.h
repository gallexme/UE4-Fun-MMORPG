#pragma once
#include "MT2ConnectorPrivatePCH.h"
#include "MT2Connector.h"
#include "M2CL/Core/Network/TcpClient.h"
#include "M2CL/Core/Logger.h"
class TcpClient;
class FMT2ClientThread : public FRunnable
{
public:

	/** Singleton instance, can access the thread any time via static accessor, if it is active! */
	static  FMT2ClientThread* Runnable;

	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	/** The Data Ptr */


	AMT2Connector* Client;
	TcpClient* TCPClient;
	FString authIP;
	uint16 authPort;
	FString channelIP;
	uint16 channelPort;
	/** Stop this thread? Uses Thread Safe Counter */
	FThreadSafeCounter StopTaskCounter;


	bool isRunning;

	//Done?
	bool IsFinished() const
	{
		return !isRunning;
	}

	//~~~ Thread Core Functions ~~~

	//Constructor / Destructor
	FMT2ClientThread(FString AuthIP, uint16 AuthPort, FString ChannelIP, uint16 ChannelPort, AMT2Connector* mt2Connector);
	virtual ~FMT2ClientThread();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	
	// End FRunnable interface

	/** Makes sure this thread has stopped properly */
	void EnsureCompletion();



	//~~~ Starting and Stopping Thread ~~~



	/*
	Start the thread and the worker from static (easy access)!
	This code ensures only 1 Prime Number thread will be able to run at a time.
	This function returns a handle to the newly started instance.
	*/
	static FMT2ClientThread* JoyInit(FString AuthIP, uint16 AuthPort, FString ChannelIP, uint16 ChannelPort, AMT2Connector* mt2Connector);
	static void send(void* data, uint32 length);
	static void connect(FString ip, uint16 port);
	void changePhase(int32 phase);
	void callListenerFunction(uint8 oldHeader, void* packet);
	/** Shuts down the thread. Static so it can easily be called from outside the thread context */
	static void Shutdown();

	static bool IsThreadFinished();
	
};

