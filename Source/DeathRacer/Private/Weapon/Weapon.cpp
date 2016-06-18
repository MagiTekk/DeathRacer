// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "WeaponBehavior.h"
#include "Weapon.h"


// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeapon::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UWeapon::PerformFireWeapon()
{
	WeaponBehavior->FireWeapon();
}

void UWeapon::SetWeaponBehavior(UWeaponBehavior* NewWeaponBehavior)
{
	WeaponBehavior = NewWeaponBehavior;
}

