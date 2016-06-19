// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "NormalGunBehavior.h"
#include "MachineGun.h"


AMachineGun::AMachineGun()
{
	//MachineGunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineGunMesh"));
	//MachineGunMesh->SetStaticMesh();
}

void AMachineGun::BeginPlay()
{
	UNormalGunBehavior* GunBehavior = NewObject<UNormalGunBehavior>(this, UNormalGunBehavior::StaticClass());
	Super::SetWeaponBehavior(GunBehavior);
}

// Called every frame
void AMachineGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

