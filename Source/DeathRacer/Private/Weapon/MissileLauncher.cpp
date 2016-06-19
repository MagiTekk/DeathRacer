// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "MissileLauncher.h"


AMissileLauncher::AMissileLauncher()
{
	//WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MissileLauncherMesh"));
	//WeaponMesh->SetStaticMesh();
}

void AMissileLauncher::BeginPlay()
{
	//behavior is assigned during runtime
}

// Called every frame
void AMissileLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}