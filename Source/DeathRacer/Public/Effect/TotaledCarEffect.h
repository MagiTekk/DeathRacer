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

	UParticleSystem* ExplosionEffectReference;
	UParticleSystem* FireEffectReference;
	class ADestructibleBox* DestructibleBox;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArrowComponent")
		UArrowComponent* ArrowComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Particle")
		UParticleSystemComponent* ExplosionParticleEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Particle")
		UParticleSystemComponent* FireParticleEffect;

#pragma endregion

#pragma region Sound
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sound")
		USoundCue* ExplosionSoundEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sound")
		USoundCue* FireSoundEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sound")
		UAudioComponent* FireAudioComponent;

#pragma endregion

#pragma region Methods
public:

	UFUNCTION()
		void ActivateEffect();

	UFUNCTION()
		void RemoveDebris();

	UFUNCTION()
		void DeactivateEffect();

	UFUNCTION()
		void Die();

#pragma endregion

};