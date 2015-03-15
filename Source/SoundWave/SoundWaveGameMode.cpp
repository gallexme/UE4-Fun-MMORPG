// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SoundWave.h"
#include "SoundWaveGameMode.h"
#include "SoundWaveHUD.h"
#include "SoundWaveCharacter.h"

ASoundWaveGameMode::ASoundWaveGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASoundWaveHUD::StaticClass();
}
