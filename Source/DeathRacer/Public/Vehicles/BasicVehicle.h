// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WheeledVehicle.h"
#include "BasicVehicle.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACER_API ABasicVehicle : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:

	ABasicVehicle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		UChildActorComponent* MachineGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		UChildActorComponent* ActiveWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		TArray<class UWeapon*> WeaponArray;

#pragma endregion

	
};
