// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "MachineGun.h"
#include "WeaponBehavior.h"
#include "TotaledCarEffect.h"
#include "BasicVehicle.h"


ABasicVehicle::ABasicVehicle()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArm->SetRelativeLocation(FVector(0,0,250));
	SpringArm->AddLocalRotation(FRotator(-10, 0, 0));
	SpringArm->TargetArmLength = 500.0f;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	MainCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	MainCamera->AddLocalRotation(FRotator(-10, 0, 0));

	MachineGun = CreateDefaultSubobject<UChildActorComponent>(TEXT("MachineGun"));
	MachineGun->SetChildActorClass(AMachineGun::StaticClass());
	MachineGun->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ActiveWeapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("ActiveWeapon"));
	ActiveWeapon->SetChildActorClass(AWeapon::StaticClass());
	ActiveWeapon->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	TotaledCarEffect = CreateDefaultSubobject<UChildActorComponent>(TEXT("TotaledCarEffect"));
	TotaledCarEffect->SetChildActorClass(ATotaledCarEffect::StaticClass());
	TotaledCarEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TotaledCarEffect->Deactivate();
}

void ABasicVehicle::BeginPlay()
{
	Super::BeginPlay();

	//set machine gun's owner
	AMachineGun* MachineGunActor = Cast<AMachineGun>(MachineGun->GetChildActor());
	MachineGunActor->SetOwner(this);
}

void ABasicVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasicVehicle::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	/*Movement Axes*/
	InputComponent->BindAxis("MoveForward", this, &ABasicVehicle::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABasicVehicle::MoveRight);


	/*Action Key Mapping*/
	InputComponent->BindAction("Handbrake", IE_Pressed, this, &ABasicVehicle::HandbrakeOn);
	InputComponent->BindAction("Handbrake", IE_Released, this, &ABasicVehicle::HandbrakeOff);

	InputComponent->BindAction("ApplyTurbo", IE_Pressed, this, &ABasicVehicle::ApplyTurbo);

	InputComponent->BindAction("FireWeapon", IE_Pressed, this, &ABasicVehicle::FireMachineGun);
	InputComponent->BindAction("FireWeapon", IE_Released, this, &ABasicVehicle::CeaseMachineGunFire);

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

void ABasicVehicle::MoveForward(float value)
{
	if (!_isDead)
	{
		GetVehicleMovement()->SetThrottleInput(value);
	}
}

void ABasicVehicle::MoveRight(float value)
{
	if (!_isDead)
	{
		GetVehicleMovement()->SetSteeringInput(value);
	}
}

void ABasicVehicle::HandbrakeOn()
{
	if (!_isDead)
	{
		GetVehicleMovement()->SetHandbrakeInput(true);
	}
}

void ABasicVehicle::HandbrakeOff()
{
	if (!_isDead)
	{
		GetVehicleMovement()->SetHandbrakeInput(false);
	}
}

void ABasicVehicle::ApplyTurbo()
{
	if (!_isDead)
	{
		//apply turbo
	}
}


//TODO nullBot: change it later to be able to fire the selected weapon
void ABasicVehicle::FireMachineGun()
{
	AMachineGun* MachineGunActor = Cast<AMachineGun>(MachineGun->GetChildActor());
	if (MachineGunActor)
	{
		MachineGunActor->FireWeapon();
	}
}

void ABasicVehicle::CeaseMachineGunFire()
{
	AMachineGun* MachineGunActor = Cast<AMachineGun>(MachineGun->GetChildActor());
	if (MachineGunActor)
	{
		MachineGunActor->CeaseFire();
	}
}

void ABasicVehicle::ApplyDamage(float value)
{
	if (!_isDead)
	{
		_health = _health - (value / armorValue);
	}

	if (_health <= 0 && !_isDead)
	{
		Die();
	}
}

void ABasicVehicle::Die()
{
	if (_isDead)
	{
		return;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Red, FString::Printf(TEXT("Some variable values: x: %f, y: %f"), x, y));
	GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Yellow, FString::Printf(TEXT("I DIED!!: %s"), *driverName.ToString()));

	//trigger effect
	TotaledCarEffect->Activate();
	ATotaledCarEffect* carEffect = Cast<ATotaledCarEffect>(TotaledCarEffect->GetChildActor());
	if (carEffect)
	{
		carEffect->ActivateEffect();
	}

	_isDead = true;

	//handle deactivation
	GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &ABasicVehicle::OnEffectFinished, 6.0f, false);
}

void ABasicVehicle::OnEffectFinished()
{
	GetWorld()->GetTimerManager().ClearTimer(_TimerHandle);
	ATotaledCarEffect* carEffect = Cast<ATotaledCarEffect>(TotaledCarEffect->GetChildActor());
	carEffect->RemoveDebris();
}
