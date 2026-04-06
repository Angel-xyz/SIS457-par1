// Fill out your copyright notice in the Description page of Project Settings.


#include "GateWall.h"

void AGateWall::UpdateWallBehavior(float DeltaTime)
{
    // Se mueve en Z, por lo que NUNCA invadirá la celda de otro muro
    FVector NewLocation = GetActorLocation();
    float ZOffset = FMath::Sin(GetGameTimeSinceCreation()) * 150.f; // Sube hasta 150 unidades
    NewLocation.Z = 150.f + ZOffset; // Base Z = 150
    SetActorLocation(NewLocation);
}