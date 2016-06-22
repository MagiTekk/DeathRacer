#include "DeathRacer.h"
#include "DoomBackWheel.h"

UDoomBackWheel::UDoomBackWheel()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> wheelMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cylinder.Cylinder'"));
	CollisionMesh = wheelMesh.Object;
	ShapeRadius = 57.f;
	ShapeWidth = 30.0f;
	bAffectedByHandbrake = true;
	SteerAngle = 0.0f;
	TireType->SetFrictionScale(3.0f);
}