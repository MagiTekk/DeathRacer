// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "Doom.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "DeathRacerGameMode.h"

ADeathRacerGameMode::ADeathRacerGameMode()
{
	DefaultPawnClass = ADoom::StaticClass();
}

AActor * ADeathRacerGameMode::ChoosePlayerStart_Implementation(AController * Player)
{
	for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		APlayerStart *PlayerStart = *ActorItr;
		if (!PlayerStart->IsOwnedBy(Player))
		{
			return PlayerStart;
		}
	}
	return Super::ChoosePlayerStart_Implementation(Player);
}



//UE_LOG(LogTemp, Warning, TEXT("ReactivatePlayWavesButton - %s"), *ActorItr->GetName());
