// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "Doom.h"


ADoom::ADoom()
{
	//Set mesh
	ConstructorHelpers::FObjectFinder<USkeletalMesh> skMesh(TEXT("SkeletalMesh'/Game/Vehicles/Buggy/Mesh/SK_Buggy_Vehicle.SK_Buggy_Vehicle'"));
	GetMesh()->SetSkeletalMesh(skMesh.Object);

	//Set animation blueprint class
	ConstructorHelpers::FClassFinder<UObject> doomAnimationClass(TEXT("/Game/Vehicles/Buggy/Blueprints/BP_VehicleAnimation"));
	GetMesh()->SetAnimInstanceClass(doomAnimationClass.Class);

	//Set wheels
	ConstructorHelpers::FObjectFinder<UClass> frontWheel(TEXT("Blueprint'/Game/Vehicles/Buggy/Blueprints/BP_FrontWheel.BP_FrontWheel_C'"));
	ConstructorHelpers::FObjectFinder<UClass> backWheel(TEXT("Blueprint'/Game/Vehicles/Buggy/Blueprints/BP_BackWheel.BP_BackWheel_C'"));

	GetVehicleMovement()->WheelSetups.SetNum(4); //set number of wheels
	GetVehicleMovement()->WheelSetups[0].WheelClass = frontWheel.Object;
	GetVehicleMovement()->WheelSetups[0].BoneName = FName("F_L_wheelJNT");
	GetVehicleMovement()->WheelSetups[1].WheelClass = frontWheel.Object;
	GetVehicleMovement()->WheelSetups[1].BoneName = FName("F_R_wheelJNT");
	GetVehicleMovement()->WheelSetups[2].WheelClass = backWheel.Object;
	GetVehicleMovement()->WheelSetups[2].BoneName = FName("B_L_wheelJNT");
	GetVehicleMovement()->WheelSetups[3].WheelClass = backWheel.Object;
	GetVehicleMovement()->WheelSetups[3].BoneName = FName("B_R_wheelJNT");
}

void ADoom::BeginPlay()
{
	Super::BeginPlay();
}

void ADoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}