// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Time.h"

AEnemigo_Aereo::AEnemigo_Aereo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnmigoMeshAereo(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	EnemigoMesh->SetStaticMesh(EnmigoMeshAereo.Object);

}

void AEnemigo_Aereo::Tick(float DeltaTime)
{
	srand(time(NULL));

	float rand1 = rand() % 50 - 20;
	float rand2 = rand() % 50 - 20;

	MoveSpeed = 100.0f;

	const FVector Move = FVector(rand1, rand2, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector Movement = Move * MoveSpeed * DeltaTime;

	if (Movement.SizeSquared() > 1.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

	}

}

//void AEnemigo_Aereo::UpdateMovement(float DeltaTime)
//{
	//Current_Location = this->GetActorLocation();

	//Current_Location.X += FMath::Sin(TotalTime + RandomStart);
	//Current_Location.Y += FMath::Sin(TotalTime + RandomStart);

	//this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	//TotalTime += DeltaTime;

//}
