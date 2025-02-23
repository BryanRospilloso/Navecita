// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemigo.generated.h"

class UCapsuleComponent;

UCLASS()
class NAVECITA_API AEnemigo : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* EnemigoMesh;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//virtual void UpdateMovement(float DeltaTime);
	
	//UPROPERTY(EditAnywhere)
		//FVector Current_Velocity;

	//FVector Current_Location;
	//float TotalTime;
	//float RandomStart;
	float MoveSpeed;
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetEnemigoMesh() const { return EnemigoMesh; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCapsuleComponent* GetCollisionComponent() const { return CollisionComponent; }

};
