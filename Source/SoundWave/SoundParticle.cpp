// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundWave.h"
#include "SoundParticle.h"


// Sets default values
ASoundParticle::ASoundParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoundParticle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoundParticle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

