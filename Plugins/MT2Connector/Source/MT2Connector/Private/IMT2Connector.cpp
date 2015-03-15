#include "MT2ConnectorPrivatePCH.h"
#include "IMT2Connector.h"






void IMT2Connector::StartupModule()
{
}

void IMT2Connector::ShutdownModule()
{
}

bool IMT2Connector::IsAvailable()
{
	return FModuleManager::Get().IsModuleLoaded("MT2Connector");
}

IMT2Connector& IMT2Connector::Get()
{
	return FModuleManager::LoadModuleChecked< IMT2Connector >("MT2Connector");
}

IMPLEMENT_MODULE(IMT2Connector, MT2Connector)