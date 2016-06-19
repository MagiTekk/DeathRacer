// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon/Weapon.h"
#include "MissileLauncher.generated.h"

/**
*
*/
UCLASS()
class DEATHRACER_API AMissileLauncher : public AWeapon
{
	GENERATED_BODY()

public:

	AMissileLauncher();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
};