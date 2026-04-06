// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MazeWall.h"
#include "GateWall.generated.h"

/**
 * 
 */
UCLASS()
class NAVESLAB01USFX_API AGateWall : public AMazeWall
{
	GENERATED_BODY()

protected:
	virtual void UpdateWallBehavior(float DeltaTime) override;
};
