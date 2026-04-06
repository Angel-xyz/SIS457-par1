// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceEntity.h"
#include "EnemyErraticShip.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX_API AEnemyErraticShip : public ASpaceEntity
{
	GENERATED_BODY()
public:
	AEnemyErraticShip();
protected:
	virtual void ExecuteBehavior(float DeltaTime) override;
};
