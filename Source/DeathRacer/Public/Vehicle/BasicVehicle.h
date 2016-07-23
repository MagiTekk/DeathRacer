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

#pragma region variables
private:
	float _health = 100;
	FName _driverName = TEXT("noName");

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
		float armorValue; //1 - 10

#pragma endregion

#pragma region Components
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		UChildActorComponent* MachineGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		UChildActorComponent* ActiveWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
		TArray<class AWeapon*> WeaponArray;

#pragma endregion

#pragma region InputCallbacks
public:

	/** Called for forwards/backward input */
	void MoveForward(float value);
	void MoveRight(float value);
	void HandbrakeOn();
	void HandbrakeOff();
	void ApplyTurbo();
	void FireMachineGun();
	void CeaseMachineGunFire();

#pragma endregion

#pragma region Methods
public:
	void ApplyDamage(float value);
	void Die();

#pragma endregion

};
