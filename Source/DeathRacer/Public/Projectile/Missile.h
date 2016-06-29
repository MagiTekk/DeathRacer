// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Missile.generated.h"


UCLASS()
class DEATHRACER_API AMissile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AMissile();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

#pragma region Variables
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int32 Damage;

#pragma endregion

#pragma region Components
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* MissileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Explosion")
		AActor* Explosion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Particle")
		UParticleEmitter* TraceParticle;

	UPROPERTY(BlueprintReadOnly, Category = "Material")
		UMaterialInstanceDynamic* DynamicInstance;

	//UPROPERTY(BlueprintReadOnly, Category = "Material")
		//UHomingBehavior* HomingBehavior; or just an enum?

#pragma endregion

};
