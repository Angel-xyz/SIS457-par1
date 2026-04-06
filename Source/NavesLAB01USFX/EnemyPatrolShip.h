// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceEntity.h"
#include "EnemyPatrolShip.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX_API AEnemyPatrolShip : public ASpaceEntity
{
	GENERATED_BODY()
public:
	AEnemyPatrolShip();
	
protected:
	virtual void ExecuteBehavior(float DeltaTime) override;
};
