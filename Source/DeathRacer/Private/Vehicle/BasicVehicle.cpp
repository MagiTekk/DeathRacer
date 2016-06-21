// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "MachineGun.h"
#include "BasicVehicle.h"


ABasicVehicle::ABasicVehicle()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SpringArm->TargetArmLength = 300.0f;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	MainCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	MachineGun = CreateDefaultSubobject<UChildActorComponent>(TEXT("MachineGun"));
	MachineGun->SetChildActorClass(AMachineGun::StaticClass());
	MachineGun->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ActiveWeapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("ActiveWeapon"));
	ActiveWeapon->SetChildActorClass(AWeapon::StaticClass());
	ActiveWeapon->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABasicVehicle::BeginPlay()
{
	Super::BeginPlay();

	AMachineGun* MachineGunActor = Cast<AMachineGun>(MachineGun->GetChildActor());
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