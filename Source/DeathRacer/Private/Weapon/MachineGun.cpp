// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "NormalGunBehavior.h"
#include "MachineGun.h"


AMachineGun::AMachineGun()
{
	//WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineGunMesh"));
	//WeaponMesh->SetStaticMesh();
}

void AMachineGun::BeginPlay()
{
	UNormalGunBehavior* GunBehavior = NewObject<UNormalGunBehavior>(this, UNormalGunBehavior::StaticClass());
	GunBehavior->SourceActor = this;
	Super::SetWeaponBehavior(GunBehavior);
}

// Called every frame
void AMachineGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

