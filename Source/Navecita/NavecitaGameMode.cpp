// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavecitaGameMode.h"
#include "NavecitaPawn.h"

ANavecitaGameMode::ANavecitaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavecitaPawn::StaticClass();
}

