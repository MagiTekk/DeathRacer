#include "DeathRacer.h"
#include "Engine/DestructibleMesh.h"
#include "DestructibleBox.h"
#include "TotaledCarEffect.h"

ATotaledCarEffect::ATotaledCarEffect()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	//I had to simulate physics and disable gravity because of a bug where the DM is not visible after being spawned by code
	/*ConstructorHelpers::FObjectFinder<UDestructibleMesh> destructibleCube(TEXT("DestructibleMesh'/Game/Mesh/Destructible/Shape_Cube_DM.Shape_Cube_DM'"));
	DestructibleMesh = CreateDefaultSubobject<UDestructibleComponent>(TEXT("DestructibleMesh"));
	DestructibleMesh->SetDestructibleMesh(destructibleCube.Object);
	DestructibleMesh->SetMobility(EComponentMobility::Movable);

	DestructibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DestructibleMesh->SetCollisionObjectType(ECollisionChannel::ECC_Vehicle);

	EnableCollisions();
	
	DestructibleMesh->SetVisibility(false);
	DestructibleMesh->Deactivate();
	RootComponent = DestructibleMesh;
	*/

	ConstructorHelpers::FObjectFinder<UParticleSystem> flashEmitter(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ParticleEffectReference = flashEmitter.Object;

	ParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleEffect"));
	ParticleEffect->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	ParticleEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<USoundCue> bulletSpawnSound(TEXT("SoundCue'/Game/StarterContent/Audio/Explosion_Cue.Explosion_Cue'"));
	SoundCueEffect = bulletSpawnSound.Object;

	RootComponent = ParticleEffect;
}

void ATotaledCarEffect::EnableCollisions()
{
	/*
	//Block All!
	DestructibleMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//ignore only vehicle and pawn
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Ignore);
	*/
}

void ATotaledCarEffect::DisableCollisions()
{
	//Ignore All!
	//DestructibleMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// Called when the game starts
void ATotaledCarEffect::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATotaledCarEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATotaledCarEffect::ActivateEffect()
{
	DestructibleBox = GetWorld()->SpawnActor<ADestructibleBox>(ADestructibleBox::StaticClass(), this->GetActorLocation(), this->GetActorRotation());

	/*DestructibleMesh->Activate();
	DestructibleMesh->SetVisibility(true);
	DestructibleMesh->ApplyRadiusDamage(100.0f, this->GetActorLocation(), 360.0f, 6000.0f, true);*/

	//spawn effect
	ParticleEffect->SetTemplate(ParticleEffectReference);

	//play sound
	UGameplayStatics::PlaySoundAtLocation(this, SoundCueEffect, GetActorLocation());
}

void ATotaledCarEffect::DeactivateEffect()
{
	if (DestructibleMesh)
	{
		DestructibleMesh->DestroyComponent();
	}

	if (DestructibleBox)
	{
		DestructibleBox->Die();
	}
	
	/*DestructibleMesh->SetVisibility(false);
	DisableCollisions();*/
}

//should I kill the effect or is it better to just deactivate it?, it depends on the game I guess, If I will use the same vehicle again then do not destroy
void ATotaledCarEffect::Die()
{
	if (DestructibleMesh)
	{
		DestructibleMesh->DestroyComponent();
	}

	//destroy
	Destroy();
}