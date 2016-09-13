#include "DeathRacer.h"
#include "Engine/DestructibleMesh.h"
#include "DestructibleBox.h"
#include "TotaledCarEffect.h"

ATotaledCarEffect::ATotaledCarEffect()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	RootComponent = ArrowComponent;

	ConstructorHelpers::FObjectFinder<UParticleSystem> fireEmitter(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	FireEffectReference = fireEmitter.Object;

	FireParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticleEffect"));
	FireParticleEffect->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	FireParticleEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<UParticleSystem> flashEmitter(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	ExplosionEffectReference = flashEmitter.Object;

	ExplosionParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionParticleEffect"));
	ExplosionParticleEffect->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	ExplosionParticleEffect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ConstructorHelpers::FObjectFinder<USoundCue> explosionSoundCue(TEXT("SoundCue'/Game/StarterContent/Audio/Explosion_Cue.Explosion_Cue'"));
	ExplosionSoundEffect = explosionSoundCue.Object;

	ConstructorHelpers::FObjectFinder<USoundCue> fireSoundCue(TEXT("SoundCue'/Game/StarterContent/Audio/Fire01_Cue.Fire01_Cue'"));
	FireSoundEffect = fireSoundCue.Object;

	FireAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("FireAudioComponent"));
	FireAudioComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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

	//spawn effect
	FireParticleEffect->SetTemplate(FireEffectReference);

	//spawn effect
	ExplosionParticleEffect->SetTemplate(ExplosionEffectReference);

	//play sound
	UGameplayStatics::PlaySoundAtLocation(this, ExplosionSoundEffect, GetActorLocation());

	//play sound
	FireAudioComponent->SetSound(FireSoundEffect);
	FireAudioComponent->Play();
}

void ATotaledCarEffect::RemoveDebris()
{
	if (DestructibleBox)
	{
		DestructibleBox->Die();
	}
}

void ATotaledCarEffect::DeactivateEffect()
{
	if (DestructibleBox)
	{
		DestructibleBox->Die();
	}

	if (FireAudioComponent)
	{
		FireAudioComponent->Stop();
	}
}

//should I kill the effect or is it better to just deactivate it?, it depends on the game I guess, If I will use the same vehicle again then do not destroy
void ATotaledCarEffect::Die()
{
	//destroy
	Destroy();
}