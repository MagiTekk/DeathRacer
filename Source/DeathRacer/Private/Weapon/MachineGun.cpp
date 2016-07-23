// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "NormalGunBehavior.h"
#include "BulletSpawnEffect.h"
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

	ConstructorHelpers::FObjectFinder<UStaticMesh> leftGunmesh(TEXT("StaticMesh'/Game/Mesh/MachineGun/MachineGunMesh.MachineGunMesh'"));
	LeftGun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftGun"));
	LeftGun->SetStaticMesh(leftGunmesh.Object);
	LeftGun->SetRelativeScale3D(FVector(4.0f, 0.1f, 1.0f));
	LeftGun->SetRelativeLocation(FVector(150.0f, -55.0f, 0.0f));
	LeftGun->SetCollisionProfileName(TEXT("OverlapAll"));
	LeftGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftGun->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<UStaticMesh> rightGunmesh(TEXT("StaticMesh'/Game/Mesh/MachineGun/MachineGunMesh.MachineGunMesh'"));
	RightGun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightGun"));
	RightGun->SetStaticMesh(rightGunmesh.Object);
	RightGun->SetRelativeScale3D(FVector(4.0f, 0.1f, 1.0f));
	RightGun->SetRelativeLocation(FVector(150.0f, 55.0f, 0.0f));
	RightGun->SetCollisionProfileName(TEXT("OverlapAll"));
	RightGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightGun->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	BulletSpawnEffect = CreateDefaultSubobject<UChildActorComponent>(TEXT("BulletSpawnEffect"));
	BulletSpawnEffect->SetChildActorClass(ABulletSpawnEffect::StaticClass());
	BulletSpawnEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	if (isActive && !bTimerRunning)
	{
		bTimerRunning = true;
		PerformFireWeapon();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMachineGun::TimerCallback, 0.1f, false);
	}
}

void AMachineGun::FireWeapon()
{
	isActive = true;
}

void AMachineGun::CeaseFire()
{
	isActive = false;
}

void AMachineGun::TimerCallback()
{
	bTimerRunning = false;
}

void AMachineGun::Destroyed()
{
	Super::Destroyed();
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}