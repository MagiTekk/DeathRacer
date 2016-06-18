#pragma once

#include "Object.h"
#include "WeaponBehavior.generated.h"

UCLASS()
class DEATHRACER_API UWeaponBehavior : public UObject
{
	GENERATED_BODY()

public:

	UWeaponBehavior();

	virtual void FireWeapon();
};

