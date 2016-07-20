#pragma once

#include "GameFramework/Actor.h"
#include "BulletSpawnEffect.generated.h"


UCLASS()
class DEATHRACER_API ABulletSpawnEffect : public AActor
{
	GENERATED_BODY()

public:

	ABulletSpawnEffect();

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

#pragma endregion

};