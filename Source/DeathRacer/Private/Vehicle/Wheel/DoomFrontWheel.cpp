#include "DeathRacer.h"
#include "DoomFrontWheel.h"

UDoomFrontWheel::UDoomFrontWheel()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> wheelMesh(TEXT("StaticMesh'/Engine/EngineMeshes/Cylinder.Cylinder'"));
	CollisionMesh = wheelMesh.Object;
	ShapeRadius = 52.f;
	ShapeWidth = 23.0f;
	bAffectedByHandbrake = false;
	SteerAngle = 55.f;
	TireType->SetFrictionScale(3.0f);

	//couldn't find a way to pass a TireType data asset created in c++ to this TireType parameter
	//static ConstructorHelpers::FObjectFinder<UTireType> TireTypeObj(TEXT("/Game/Vehicles/Buggy/Blueprints/DA_TireType.DA_TireType"));
	//TireType = TireTypeObj.Object;
}