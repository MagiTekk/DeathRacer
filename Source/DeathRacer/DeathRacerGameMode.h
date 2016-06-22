// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "DeathRacerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACER_API ADeathRacerGameMode : public AGameMode
{
	GENERATED_BODY()

	ADeathRacerGameMode();
	
	class AActor* ChoosePlayerStart_Implementation(AController* Player) override; 
	
	
};
