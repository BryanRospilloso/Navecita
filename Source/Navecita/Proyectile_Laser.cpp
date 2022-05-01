// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectile_Laser.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AProyectile_Laser::AProyectile_Laser()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnmigoMeshAereo(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	ProjectileMesh->SetStaticMesh(EnmigoMeshAereo.Object);
	//Game/Meshes/LaserBolt.LaserBolt
}

void AProyectile_Laser::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();

}
