// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "Bullet.h"


// Sets default values for this component's properties
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> bulletMesh(TEXT("StaticMesh'/Game/Mesh/Bullet/BulletStaticMesh.BulletStaticMesh'"));
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	BulletMesh->SetStaticMesh(bulletMesh.Object);
	BulletMesh->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	BulletMesh->AttachTo(RootComponent);

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	CollisionCapsule->SetCapsuleRadius(50.0f);
	CollisionCapsule->SetRelativeScale3D(FVector(0.000632f, 0.166855f, 0.286425f));
	CollisionCapsule->AttachTo(RootComponent);

	//attatch both component to defatult scene root
}

// Called when the game starts
void ABullet::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}