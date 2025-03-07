// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon/Weapon.h"
#include "MachineGun.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACER_API AMachineGun : public AWeapon
{
	GENERATED_BODY()

private:

	bool bTimerRunning = false;
	
public:

	AMachineGun();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* LeftGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* RightGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UChildActorComponent* BulletSpawnEffect;


#pragma region Variables
public:

	//as long as the user presses the button, the weapon fires
	bool isActive;
	float damageValue;

#pragma endregion

#pragma region Methods

private:
	void TimerCallback();

public:
	virtual void Destroyed() override;
	void FireWeapon();
	void CeaseFire();

#pragma endregion

#pragma region Timer
public:

	/* Handle to manage the timer */
	FTimerHandle TimerHandle;

#pragma endregion
};
