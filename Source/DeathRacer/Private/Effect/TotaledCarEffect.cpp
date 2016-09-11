#include "DeathRacer.h"
#include "Engine/DestructibleMesh.h"
#include "TotaledCarEffect.h"

ATotaledCarEffect::ATotaledCarEffect()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	//I had to simulate physics and disable gravity because of a bug where the DM is not visible after being spawned by code
	ConstructorHelpers::FObjectFinder<UDestructibleMesh> destructibleCube(TEXT("DestructibleMesh'/Game/Mesh/Destructible/Shape_Cube_DM.Shape_Cube_DM'"));
	DestructibleMesh = CreateDefaultSubobject<UDestructibleComponent>(TEXT("DestructibleMesh"));
	DestructibleMesh->SetDestructibleMesh(destructibleCube.Object);
	DestructibleMesh->SetMobility(EComponentMobility::Movable);
	DestructibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	
	DestructibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DestructibleMesh->SetCollisionObjectType(ECollisionChannel::ECC_Vehicle);

	//Block All!
	DestructibleMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//ignore only vehicle and pawn
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Ignore);
	
	
	//DestructibleMesh->SetCollisionObjectType(ECollisionChannel::ECC_Vehicle);
	
	//DestructibleMesh->SetVisibility(false);
	DestructibleMesh->Deactivate();
	RootComponent = DestructibleMesh;

	ConstructorHelpers::FObjectFinder<UParticleSystem> flashEmitter(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ParticleEffectReference = flashEmitter.Object;

	ParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleEffect"));
	//ParticleEffect->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	ParticleEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<USoundCue> bulletSpawnSound(TEXT("SoundCue'/Game/StarterContent/Audio/Explosion_Cue.Explosion_Cue'"));
	SoundCueEffect = bulletSpawnSound.Object;
	
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
	DestructibleMesh->ApplyDamage(200.0f, this->GetActorLocation(), FVector(10.0f, 10.0f, 10.0f), 50.0f);

	//spawn effect
	ParticleEffect->SetTemplate(ParticleEffectReference);

	//play sound
	UGameplayStatics::PlaySoundAtLocation(this, SoundCueEffect, GetActorLocation());
}
