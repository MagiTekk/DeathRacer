// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "NormalGunBehavior.h"
#include "MachineGun.h"


AMachineGun::AMachineGun()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	//PrimaryActorTick.bAllowTickOnDedicatedServer = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> machineGunmesh(TEXT("StaticMesh'/Game/Mesh/MachineGun/MachineGunMesh.MachineGunMesh'"));
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MachineGunMesh"));
	WeaponMesh->SetStaticMesh( machineGunmesh.Object );
	WeaponMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = WeaponMesh;
}

void AMachineGun::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickEnabled(true);
	isActive = false;

	UNormalGunBehavior* GunBehavior = NewObject<UNormalGunBehavior>(this, UNormalGunBehavior::StaticClass());
	GunBehavior->SourceActor = this;
	Super::SetWeaponBehavior(GunBehavior);
}

// Called every frame
void AMachineGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); //does not fire
	if (isActive)
	{
		PerformFireWeapon();
	}
}

void AMachineGun::EnableWeapon()
{
	isActive = true;
}

void AMachineGun::DisableWeapon()
{
	isActive = false;
}