// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "NormalGunBehavior.h"
#include "MachineGun.h"


UMachineGun::UMachineGun()
{
	//MachineGunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineGunMesh"));
	//MachineGunMesh->SetStaticMesh();
}

void UMachineGun::BeginPlay()
{
	Super::SetWeaponBehavior(new UNormalGunBehavior());
}

void UMachineGun::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

