// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "MT2ConnectorPrivatePCH.h"
#include "M2CL/Core/Network/Packets/Packets.h"
#include "GameFramework/Actor.h"
#include "M2CL/Core/PythonAPI/ListenerModule.h"
#include "MT2Connector.generated.h"
UCLASS(config = Game)
class AMT2Connector : public AActor
{
	GENERATED_BODY()
public:
	AMT2Connector();
	void OnPacket(uint8 header, void* packet);
	UFUNCTION(BlueprintImplementableEvent, Category = "MT2-Network")
		virtual void OnLoginSuccess(const int32 loginkey, const int32 result);
	UFUNCTION(BlueprintImplementableEvent, Category = "MT2-Network")
		virtual void OnChangePhase(const int32& phase);
	UFUNCTION(BlueprintImplementableEvent, Category = "MT2-Network")
		virtual void OnPacketLog(const FString & message);
	UFUNCTION(BlueprintImplementableEvent, Category = "MT2-Network")
		virtual void Log(const FString & message);
	UFUNCTION(BlueprintCallable, Category = "MT2-Network")
		void ConnectToChannel( FString channelIP, int32 channelPort);
	UFUNCTION(BlueprintCallable, Category = "MT2-Network")
		void ConnectToServer(FString authIP, int32 authPort, FString channelIP, int32 channelPort);
	UFUNCTION(BlueprintCallable, Category = "MT2-Network")
		void Login(FString username, FString password);
	UFUNCTION(BlueprintCallable, Category = "MT2-Network")
		void SendLoginKey(FString username,int32 loginKey);
	//UFUNCTION(BlueprintCallable, Category = "MT2-Network")
	//void ConnectToServer(FString IP,  PORT);
};


