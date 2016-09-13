// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DestructibleBox.generated.h"


UCLASS()
class DEATHRACER_API ADestructibleBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ADestructibleBox();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

#pragma region Components
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UDestructibleComponent* DestructibleMesh;

#pragma endregion

#pragma region Methods
public:

	UFUNCTION()
		void ActivateEffect();

	UFUNCTION()
		void EnableCollisions();

	UFUNCTION()
		void Die();

#pragma endregion

};
