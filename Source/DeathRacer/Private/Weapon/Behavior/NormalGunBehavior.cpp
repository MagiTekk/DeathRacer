#include "DeathRacer.h"
#include "Bullet.h"
#include "BulletSpawnEffect.h"
#include "NormalGunBehavior.h"


UNormalGunBehavior::UNormalGunBehavior()
{
	spawnPosition = 1;
}

void UNormalGunBehavior::FireWeapon()
{
	Super::FireWeapon();
	
	//GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Yellow, FString::FString("FIRE_WEAPON_ACTIVATED"));
	//UE_LOG(LogTemp, Warning, TEXT("FIRE WEAPON ACTIVATED"));

	FVector Origin;
	FVector BoundsExtent;
	SourceActor->GetActorBounds(false, Origin, BoundsExtent);

	//spawn the bullet on the sides of the actor
	FVector WorldActorLocation = SourceActor->GetActorLocation();
	FVector SpawnPosition = WorldActorLocation + FVector( 0.0f, (BoundsExtent.Y + 0.0f)  *  spawnPosition, 0.0f);

	UE_LOG(LogTemp, Warning, TEXT("ACTOR LOCATION: X: %d, Y: %d, Z: %d"), WorldActorLocation.X, WorldActorLocation.Y, WorldActorLocation.Z);

	// spawn bullet
	SourceActor->GetWorld()->SpawnActor<ABullet>(ABullet::StaticClass(), SpawnPosition, SourceActor->GetActorRotation());

	//gunshot effect
	SourceActor->GetWorld()->SpawnActor<ABulletSpawnEffect>(ABulletSpawnEffect::StaticClass(), SpawnPosition, SourceActor->GetActorRotation());

	//move position of for the next bullet
	spawnPosition *= -1;

	//empty shell
	//GetWorld()->SpawnActor<AActor>(Empty_Shell, Mesh->GetComponentLocation() + (0.0f, 0.0f, 4.0f), LaserSource->GetComponentRotation() + perperndicularRotation);
}