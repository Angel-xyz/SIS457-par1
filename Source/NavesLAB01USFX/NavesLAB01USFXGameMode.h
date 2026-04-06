// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceEntity.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;

UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesLAB01USFXGameMode();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	
	TArray<AEnemigo*> AEnemigos;

	FTimerHandle TimerFormacion;

	void FormarNavesFrentePawn();

	APawn* PlayerPawn;  // Referencia al Pawn

	float IntervaloFormacion = 5.0f;

	float EspaciadoVertical = 100.0f;

	TArray<ASpaceEntity*> Enemies;
};



