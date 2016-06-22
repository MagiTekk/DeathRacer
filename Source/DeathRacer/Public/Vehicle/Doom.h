// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasicVehicle.h"
#include "Doom.generated.h"

/**
*
*/
UCLASS()
class DEATHRACER_API ADoom : public ABasicVehicle
{
	GENERATED_BODY()

public:

	ADoom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

};
