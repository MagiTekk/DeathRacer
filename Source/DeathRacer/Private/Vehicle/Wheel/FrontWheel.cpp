#include "DeathRacer.h"
#include "FrontWheel.h"

UFrontWheel::UFrontWheel()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> wheelMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cylinder.Cylinder'"));
	//GetCollisionMesh()->set
	//CollisionMesh = wheelMesh.Object;
}