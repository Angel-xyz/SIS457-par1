// Fill out your copyright notice in the Description page of Project Settings.


#include "BlinkingWall.h"

void ABlinkingWall::UpdateWallBehavior(float DeltaTime)
{
    // Desaparece y pierde colisión cada 2 segundos
    int32 TimeInt = FMath::FloorToInt(GetGameTimeSinceCreation());
    bool bIsHidden = (TimeInt % 4) < 2; // 2 segs visible, 2 segs invisible

    SetActorHiddenInGame(bIsHidden);
    SetActorEnableCollision(!bIsHidden);
}