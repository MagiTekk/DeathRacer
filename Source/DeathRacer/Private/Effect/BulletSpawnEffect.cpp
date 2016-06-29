#include "DeathRacer.h"
#include "BulletSpawnEffect.h"

ABulletSpawnEffect::ABulletSpawnEffect()
{
	ConstructorHelpers::FObjectFinder<UParticleSystem> flashEmitter(TEXT("ParticleSystem'/Game/Particles/MuzzleFlash.MuzzleFlash'"));
	ParticleEffectReference = flashEmitter.Object;

	ParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleEffect"));
	//ParticleEffect->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	ParticleEffect->AttachTo(RootComponent);

	ConstructorHelpers::FObjectFinder<USoundCue> bulletSpawnSound(TEXT("SoundCue'/Game/Audio/SoundCues/MachineGunShotSound_Cue.MachineGunShotSound_Cue'"));
	SoundCueEffect = bulletSpawnSound.Object;
}

// Called when the game starts
void ABulletSpawnEffect::BeginPlay()
{
	Super::BeginPlay();

	//spawn effect
	ParticleEffect->SetTemplate(ParticleEffectReference);

	//play sound
	UGameplayStatics::PlaySoundAtLocation(this, SoundCueEffect, GetActorLocation());

}

// Called every frame
void ABulletSpawnEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}