// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "Missile.h"


// Sets default values for this component's properties
AMissile::AMissile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts
void AMissile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}