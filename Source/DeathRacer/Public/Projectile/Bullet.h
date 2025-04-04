// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"


UCLASS()
class DEATHRACER_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ABullet();

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
		UArrowComponent* ArrowComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
		USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Material")
		UMaterialInstanceDynamic* DynamicInstance;

#pragma endregion

#pragma region Methods
public:

	UFUNCTION()
		void OnOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

#pragma endregion

};
