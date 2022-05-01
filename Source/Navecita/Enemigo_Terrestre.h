// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "Enemigo_Terrestre.generated.h"

UCLASS()
class NAVECITA_API AEnemigo_Terrestre : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigo_Terrestre();

	//virtual void UpdateMovement(float DeltaTime);

	virtual void Tick(float DeltaTime) override;
	
};
