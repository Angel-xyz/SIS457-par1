// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFXGameMode.generated.h"

UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesLAB01USFXGameMode();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};



