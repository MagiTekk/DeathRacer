// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon/Weapon.h"
#include "MachineGun.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACER_API UMachineGun : public UWeapon
{
	GENERATED_BODY()
	
public:

	UMachineGun();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* MachineGunMesh;
};
