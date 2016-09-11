#pragma once

#include "GameFramework/Actor.h"
#include "TotaledCarEffect.generated.h"


UCLASS()
class DEATHRACER_API ATotaledCarEffect : public AActor
{
	GENERATED_BODY()

public:

	ATotaledCarEffect();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

#pragma region Components
private:

	UParticleSystem* ParticleEffectReference;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Particle")
		UParticleSystemComponent* ParticleEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UDestructibleComponent* DestructibleMesh;

#pragma endregion

#pragma region Sound
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sound")
		USoundCue* SoundCueEffect;

#pragma endregion

#pragma region Methods
public:

	UFUNCTION()
		void ActivateEffect();

	UFUNCTION()
		void DeactivateEffect();

	UFUNCTION()
		void EnableCollisions();

	UFUNCTION()
		void DisableCollisions();

	UFUNCTION()
		void Die();

#pragma endregion

};