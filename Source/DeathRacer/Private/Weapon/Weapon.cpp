// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "WeaponBehavior.h"
#include "Weapon.h"


// Sets default values for this component's properties
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//PrimaryActorTick.bStartWithTickEnabled = true;
	//PrimaryActorTick.bAllowTickOnDedicatedServer = true;
}

// Called when the game starts
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::PerformFireWeapon()
{
	WeaponBehavior->FireWeapon();
}

void AWeapon::SetWeaponBehavior(UWeaponBehavior* NewWeaponBehavior)
{
	WeaponBehavior = NewWeaponBehavior;
}

