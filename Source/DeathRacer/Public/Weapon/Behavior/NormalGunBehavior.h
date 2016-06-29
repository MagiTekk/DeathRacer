#pragma once

#include "WeaponBehavior.h"
#include "NormalGunBehavior.generated.h"

UCLASS()
class DEATHRACER_API UNormalGunBehavior : public UWeaponBehavior
{
	GENERATED_BODY()

public:
	UNormalGunBehavior();

	virtual void FireWeapon() override;

#pragma region Variables
public:

	//-1 spawns bullet in the left slot, +1 spawns it in the right slot
	int32 spawnPosition;

#pragma endregion

#pragma region Components
public:

	UClass* InitialParticleEffect;

#pragma endregion
};