// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "Bullet.h"


// Sets default values for this component's properties
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> bulletMesh(TEXT("StaticMesh'/Game/Mesh/Bullet/BulletMesh.BulletMesh'"));
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	BulletMesh->SetStaticMesh(bulletMesh.Object);
	BulletMesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BulletMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	BulletMesh->bGenerateOverlapEvents = true;
	RootComponent = BulletMesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetSphereRadius(150.0f);
	CollisionSphere->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	// Collision profiles are defined in DefaultEngine.ini
	CollisionSphere->SetCollisionProfileName("Projectile");
	// set up a notification for when this component overlaps something
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
	CollisionSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	//ProjectileMovement->UpdatedComponent = BulletMesh; //which component to affect the movement, by default the root component
	ProjectileMovement->InitialSpeed = 5000.f;
	ProjectileMovement->MaxSpeed = 5000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	//Die after 5 seconds by default
	InitialLifeSpan = 5.0f;
}

// Called when the game starts
void ABullet::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		//TODO nullbot: avoid contact with our owner's physics
		//OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		//Destroy();
	}
}