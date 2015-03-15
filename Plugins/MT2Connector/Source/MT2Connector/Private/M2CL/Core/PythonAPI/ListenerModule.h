#pragma once
#include "MT2ConnectorPrivatePCH.h"



#include "../Types.h"


class ListenerModule {
public:
	ListenerModule();

	~ListenerModule();
	static void AddListenerModule(ListenerModule* listener);
	static void callListenerFunctions(uint8 header, void* packet);
	void callListenerFunction(uint8 header, void* packet);


private:

	static std::vector<ListenerModule*> listeners;
};

