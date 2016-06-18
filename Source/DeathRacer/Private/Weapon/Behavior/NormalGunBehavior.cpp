#include "DeathRacer.h"
#include "NormalGunBehavior.h"


UNormalGunBehavior::UNormalGunBehavior()
{

}

void UNormalGunBehavior::FireWeapon()
{
	Super::FireWeapon();
	
	GEngine->AddOnScreenDebugMessage(-1, 2.0, FColor::Yellow, FString::FString("FIRE_WEAPON_ACTIVATED"));
	UE_LOG(LogTemp, Warning, TEXT("FIRE WEAPON ACTIVATED"));
}