#include "DeathRacer.h"
#include "Engine/DestructibleMesh.h"
#include "DestructibleBox.h"

ADestructibleBox::ADestructibleBox()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	//I had to simulate physics and disable gravity because of a bug where the DM is not visible after being spawned by code
	ConstructorHelpers::FObjectFinder<UDestructibleMesh> destructibleCube(TEXT("DestructibleMesh'/Game/Mesh/Destructible/Shape_Cube_DM.Shape_Cube_DM'"));
	DestructibleMesh = CreateDefaultSubobject<UDestructibleComponent>(TEXT("DestructibleMesh"));
	DestructibleMesh->SetDestructibleMesh(destructibleCube.Object);
	DestructibleMesh->SetMobility(EComponentMobility::Movable);

	DestructibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DestructibleMesh->SetCollisionObjectType(ECollisionChannel::ECC_Vehicle);
	RootComponent = DestructibleMesh;

	EnableCollisions();
}

void ADestructibleBox::EnableCollisions()
{
	//Block All!
	DestructibleMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//ignore only vehicle and pawn
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	DestructibleMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECollisionResponse::ECR_Ignore);
}

// Called when the game starts
void ADestructibleBox::BeginPlay()
{
	Super::BeginPlay();
	ActivateEffect();
}

// Called every frame
void ADestructibleBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADestructibleBox::ActivateEffect()
{
	DestructibleMesh->Activate();
	DestructibleMesh->SetVisibility(true);
	DestructibleMesh->ApplyRadiusDamage(100.0f, this->GetActorLocation(), 360.0f, 5000.0f, true);
}

//should I kill the effect or is it better to just deactivate it?, it depends on the game I guess, If I will use the same vehicle again then do not destroy
void ADestructibleBox::Die()
{
	if (DestructibleMesh)
	{
		DestructibleMesh->DestroyComponent();
	}

	//destroy
	Destroy();
}