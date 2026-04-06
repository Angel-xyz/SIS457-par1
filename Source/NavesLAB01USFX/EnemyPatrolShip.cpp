// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPatrolShip.h"


AEnemyPatrolShip::AEnemyPatrolShip()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 400.0f;

	// Set the mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule"));
	if (MeshAsset.Succeeded())
	{
		EntityMesh->SetStaticMesh(MeshAsset.Object);
	}
}

void AEnemyPatrolShip::ExecuteBehavior(float DeltaTime)
{
    // Usamos el tiempo del juego para crear un movimiento de vaivén con la función Seno
    float Time = GetGameTimeSinceCreation();
    float MoveOffset = FMath::Sin(Time) * MovementSpeed * DeltaTime;
    AddActorLocalOffset(FVector(MoveOffset, 0.f, 0.f));
}