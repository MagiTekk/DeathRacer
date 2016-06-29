// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "MachineGun.h"
#include "Wheel/DoomFrontWheel.h"
#include "Wheel/DoomBackWheel.h"
#include "Doom.h"

ADoom::ADoom()
{
	//Set Mesh
	ConstructorHelpers::FObjectFinder<USkeletalMesh> skMesh(TEXT("SkeletalMesh'/Game/Vehicles/Doom/Mesh/SK_Buggy_Vehicle.SK_Buggy_Vehicle'"));
	GetMesh()->SetSkeletalMesh(skMesh.Object);

	//Set animation blueprint class
	ConstructorHelpers::FClassFinder<UObject> doomAnimationClass(TEXT("/Game/Vehicles/Doom/Blueprints/BP_VehicleAnimation"));
	GetMesh()->SetAnimInstanceClass(doomAnimationClass.Class);

	//Set Wheels
	GetVehicleMovement()->WheelSetups.SetNum(4); //set number of wheels
	GetVehicleMovement()->WheelSetups[0].WheelClass = UDoomFrontWheel::StaticClass();
	GetVehicleMovement()->WheelSetups[0].BoneName = FName("F_L_wheelJNT");
	GetVehicleMovement()->WheelSetups[1].WheelClass = UDoomFrontWheel::StaticClass();
	GetVehicleMovement()->WheelSetups[1].BoneName = FName("F_R_wheelJNT");
	GetVehicleMovement()->WheelSetups[2].WheelClass = UDoomBackWheel::StaticClass();
	GetVehicleMovement()->WheelSetups[2].BoneName = FName("B_L_wheelJNT");
	GetVehicleMovement()->WheelSetups[3].WheelClass = UDoomBackWheel::StaticClass();
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