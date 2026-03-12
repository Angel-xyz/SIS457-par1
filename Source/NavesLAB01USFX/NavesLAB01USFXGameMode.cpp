// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
}

void ANavesLAB01USFXGameMode::BeginPlay()
{
	Super::BeginPlay();

	FVector Location1(-600, 0, 150);
	FVector Location2(-600, 200, 150);

	FRotator Rotation(0, 0, 0);

	// Spawn en runtime
	UWorld* World = GetWorld();

	if (!World) return;

	AEnemigo* Enemigo1 = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), Location1, Rotation);
	AEnemigo* Enemigo2 = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), Location2, Rotation);
}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
}


