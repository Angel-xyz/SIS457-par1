// Fill out your copyright notice in the Description page of Project Settings.


#include "BreathingWall.h"

void ABreathingWall::UpdateWallBehavior(float DeltaTime)
{
    // Se encoge y se agranda
    float ScaleVal = FMath::Abs(FMath::Sin(GetGameTimeSinceCreation())) * 1.6f;
    float ScaleVal2 = FMath::Abs(FMath::Sin(GetGameTimeSinceCreation())) * 1.0f;
    SetActorScale3D(FVector(ScaleVal, 0.4f, ScaleVal2)); // Standard wall = (1.6, 0.4, 1.0f) Define in MazeWall.cpp
}