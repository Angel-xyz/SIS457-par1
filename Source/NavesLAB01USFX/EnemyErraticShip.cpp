// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyErraticShip.h"

AEnemyErraticShip::AEnemyErraticShip()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 1000.0f;

	// Set the mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B"));
	if (MeshAsset.Succeeded())
	{
		EntityMesh->SetStaticMesh(MeshAsset.Object);
	}
}

void AEnemyErraticShip::ExecuteBehavior(float DeltaTime)
{
    float RandomX = FMath::RandRange(-1.f, 1.f) * MovementSpeed * DeltaTime;
    float RandomY = FMath::RandRange(-1.f, 1.f) * MovementSpeed * DeltaTime;
    AddActorLocalOffset(FVector(RandomX, RandomY, 0.f));
}