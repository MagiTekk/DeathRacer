// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "MachineGun.h"
#include "BasicVehicle.h"


ABasicVehicle::ABasicVehicle()
{
	//ConstructorHelpers::FObjectFinder<UStaticMesh> vehicleMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	//VehicleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleMesh"));
	//VehicleMesh->SetStaticMesh(vehicleMesh.Object);
	//this->SetRootComponent(VehicleMesh);

	MachineGun = CreateDefaultSubobject<UChildActorComponent>(TEXT("MachineGun"));
	MachineGun->SetChildActorClass(UMachineGun::StaticClass());
	//FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
	//MachineGun->AttachToComponent(VehicleMesh, AttachmentRules);
	//this->SetRootComponent(MachineGun);
	//MachineGun->AttachTo(VehicleMesh);
}

void ABasicVehicle::BeginPlay()
{
	Super::BeginPlay();
	
	UMachineGun* MachineGunActor = Cast<UMachineGun>(MachineGun->GetChildActor());
	if (MachineGunActor)
	{
		MachineGunActor->PerformFireWeapon();
	}
}

void ABasicVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasicVehicle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	/*Movement Axes*/
	//InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	//InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	/*Turn Axes Keys*/
	//InputComponent->BindAxis("LookRight", this, &AMainCharacter::LookRight);
	//InputComponent->BindAxis("LookUp", this, &AMainCharacter::LookUp);

	/*Turn Axes Mouse*/
	//Another set of configuration is needed to play with the mouse, the camera system has to be redefined.
	//InputComponent->BindAxis("MouseLookRight", this, &AMainCharacter::AimRight);
	//InputComponent->BindAxis("MouseLookUp", this, &AMainCharacter::AimUp);

	/*Action Key Mapping*/
	//InputComponent->BindAction("Equip", IE_Pressed, this, &AMainCharacter::Equip_Pistol);

	//InputComponent->BindAction("Aim", IE_Pressed, this, &AMainCharacter::Trigger_Aim_In);
	//InputComponent->BindAction("Aim", IE_Released, this, &AMainCharacter::Trigger_Aim_Out);

	//InputComponent->BindAction("Reload", IE_Pressed, this, &AMainCharacter::StartReloading);

	//InputComponent->BindAction("Shoot", IE_Pressed, this, &AMainCharacter::ShootWeapon);

	//InputComponent->BindAction("Run", IE_Pressed, this, &AMainCharacter::Run);
	//InputComponent->BindAction("Run", IE_Released, this, &AMainCharacter::DoNotRun);

	//InputComponent->BindAction("ExecuteAction", IE_Pressed, this, &AMainCharacter::ExecuteContextAction);

	//InputComponent->BindAction("Pause", IE_Pressed, this, &AMainCharacter::PauseGame).bExecuteWhenPaused = true;

	/* UI Mappings */
	//InputComponent->BindAction("UINavigationUp", IE_Pressed, this, &AMainCharacter::UINavigationUp).bExecuteWhenPaused = true;
	//InputComponent->BindAction("UINavigationDown", IE_Pressed, this, &AMainCharacter::UINavigationDown).bExecuteWhenPaused = true;
	//InputComponent->BindAction("UINavigationLeft", IE_Pressed, this, &AMainCharacter::UINavigationLeft).bExecuteWhenPaused = true;
	//InputComponent->BindAction("UINavigationRight", IE_Pressed, this, &AMainCharacter::UINavigationRight).bExecuteWhenPaused = true;
	//InputComponent->BindAction("UISelectElement", IE_Pressed, this, &AMainCharacter::UISelectElement).bExecuteWhenPaused = true;
}