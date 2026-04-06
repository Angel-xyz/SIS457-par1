// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeWall.h"
#include "MazeManager.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMazeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<AMazeWall*> Quadrants[8];

	UPROPERTY(EditAnywhere, Category = "Maze Settings")
	float WorldSizeX = 4000.0f; // Ancho total

	UPROPERTY(EditAnywhere, Category = "Maze Settings")
	float WorldSizeY = 4000.0f; // Largo total

	// Cantidad de subdivisiones (Muros máximos)
	UPROPERTY(EditAnywhere, Category = "Maze Settings")
	int32 GridCols = 20; // Columnas en X

	UPROPERTY(EditAnywhere, Category = "Maze Settings")
	int32 GridRows = 20; // Filas en Y

	void GenerateMaze();
};
