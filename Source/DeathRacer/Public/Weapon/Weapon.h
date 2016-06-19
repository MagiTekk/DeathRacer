// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


UCLASS()
class DEATHRACER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AWeapon();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Behavior")
	class UWeaponBehavior* WeaponBehavior;

	UFUNCTION(Category = "Behavior")
		virtual void PerformFireWeapon();

	UFUNCTION(Category = "Behavior")
		virtual void SetWeaponBehavior(UWeaponBehavior* NewWeaponBehavior);
	
};
