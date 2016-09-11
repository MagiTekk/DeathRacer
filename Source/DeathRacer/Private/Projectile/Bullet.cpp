// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRacer.h"
#include "BasicVehicle.h"
#include "MachineGun.h"
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
	ProjectileMovement->InitialSpeed = 8000.f;
	ProjectileMovement->MaxSpeed = 8000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	//Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	Damage = 0;
}

// Called when the game starts
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	if (GetOwner()->IsA(AMachineGun::StaticClass()))
	{
		AMachineGun* machineGunActor = Cast<AMachineGun>(GetOwner());
		Damage = machineGunActor->damageValue;
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//Car owner
	AActor* weaponOwner = GetOwner();
	AActor* vehicleOwner = weaponOwner->GetOwner();

	// Only add impulse and destroy projectile if we hit a physics, but not the owner's physics!
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics() && (OtherActor != vehicleOwner))
	{
		//if a car was hit then apply damage
		if (OtherActor->IsA( ABasicVehicle::StaticClass()))
		{
			ABasicVehicle* vehicleHit = Cast<ABasicVehicle>(OtherActor);
			vehicleHit->ApplyDamage(Damage);
		}
		OtherComp->AddImpulseAtLocation(GetVelocity() * 5.0f, GetActorLocation());
		Destroy();
	}
}