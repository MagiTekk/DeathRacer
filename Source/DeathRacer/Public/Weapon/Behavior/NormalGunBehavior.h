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
};