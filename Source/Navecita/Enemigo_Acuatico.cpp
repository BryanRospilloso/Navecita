// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Acuatico.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Time.h"

AEnemigo_Acuatico::AEnemigo_Acuatico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnmigoMeshAcuatico(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	EnemigoMesh->SetStaticMesh(EnmigoMeshAcuatico.Object);

}

void AEnemigo_Acuatico::Tick(float DeltaTime)
{
	srand(time(NULL));

	float rand1 = rand() % 40 - 20;
	float rand2 = rand() % 40 - 20;

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

//void AEnemigo_Acuatico::UpdateMovement(float DeltaTime)
//{
	//Current_Location = this->GetActorLocation();

	//Current_Location.X += FMath::Sin(TotalTime + RandomStart);

	//this->SetActorLocation(Current_Location - (Current_Velocity * DeltaTime));

	//TotalTime += DeltaTime;

//}
