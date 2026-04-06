// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceEntity.h"

// Sets default values
ASpaceEntity::ASpaceEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementSpeed = 100.0f;

	EntityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntityMesh"));
	RootComponent = EntityMesh;

	// Set the mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid"));
	if (MeshAsset.Succeeded())
	{
		EntityMesh->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void ASpaceEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ExecuteBehavior(DeltaTime);
}

void ASpaceEntity::ExecuteBehavior(float DeltaTime)
{
	float YawRotationn = (45.f* DeltaTime);
	AddActorLocalRotation(FRotator(0.f, YawRotationn, 0.f));
}

