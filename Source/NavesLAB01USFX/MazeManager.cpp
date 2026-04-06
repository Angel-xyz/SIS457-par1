// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeManager.h"
#include "MazeWall.h"
#include "BlinkingWall.h"
#include "BreathingWall.h"
#include "GateWall.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMazeManager::AMazeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMazeManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Generando laberinto..."));
	GenerateMaze();

	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &AMazeManager::Teleport, 5.0f, true);
	
}

// Called every frame
void AMazeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeManager::GenerateMaze()
{
	float CellWidth = WorldSizeX / GridCols;
	float CellLength = WorldSizeY / GridRows;

	// Calcular límites lógicos de los cuadrantes (4x2)
	int32 ColumsPerQuadrant = GridCols / 4;  // Cuantas columnas entraran en cada una de las 4 filas
	int32 RowsPerQuadrant = GridRows / 2;  // Cuantas filas entraran en cada una de las 2 columnas

	// Para centrar todo en <0,0,0>
	float OffsetX = WorldSizeX / 2.0f;
	float OffsetY = WorldSizeY / 2.0f;

	// For Column in all Columns...
	for (int32 X = 0; X < GridCols; ++X)
	{
		// For Row in all Rows...
		for (int32 Y = 0; Y < GridRows; ++Y)
		{
			// 1. Lógica Procedural: 30% de probabilidad de generar un muro en esta celda
			if (FMath::RandRange(1, 100) <= 30)
			{
				// For X with size Cell Width, fixed with OffSet and centered to mid of Cell
				float RealWorldX = (X * CellWidth) - OffsetX + (CellWidth / 2.0f);
				float RealWorldY = (Y * CellLength) - OffsetY  + (CellLength / 2.0f);

				// Set SpawnLoc and a random rotation ()
				FVector SpawnLocation = FVector(RealWorldX, RealWorldY, 250.0f);
				float Rotationn = FMath::RandBool() ? 0.0f : 90.0f;
				FRotator SpawnRotation = FRotator(0.0f, Rotationn, 0.0f);

				
				// Choose one kind of wall
				int32 WallType = FMath::RandRange(0, 3);
				AMazeWall* NewWall = nullptr;

				if (WallType == 0)
				{
					NewWall = GetWorld()->SpawnActor<AMazeWall>(SpawnLocation, SpawnRotation);
				}
				else if (WallType == 1)
				{
					NewWall = GetWorld()->SpawnActor<ABlinkingWall>(SpawnLocation, SpawnRotation);
				}
				else if (WallType == 2)
				{
					NewWall = GetWorld()->SpawnActor<AGateWall>(SpawnLocation, SpawnRotation);
				}
				else
				{
					NewWall = GetWorld()->SpawnActor<ABreathingWall>(SpawnLocation, SpawnRotation);
				}
				// Almacenamiento por Cuadrantes
				if (NewWall != nullptr)
				{
					// Calcular a qué cuadrante pertenece (0 a 7)
					// If X=5: an int division will result in only 0, 1, 2 or 3
					int32 QuadX = X / ColumsPerQuadrant;
					// If y=10: and int division will result in only 0 or 1
					int32 QuadY = Y / RowsPerQuadrant; 

					// Convertir cordenadas 2D de cuadrante a índice 1D (Fórmula: Y * Ancho + X)
					// If we are at 0 row, we just count the x cuadrant
					// If we are at 1 row, we add the lenght of a column(4) and add the column name
					int32 QuadrantIndex = (QuadY * 4) + QuadX;

					// Guardar en el TArray correspondiente
					Quadrants[QuadrantIndex].Add(NewWall);
				}
			}
		}
	}

}

void AMazeManager::Teleport()
{
	float OffsetX = WorldSizeX / 2.0f;
	float OffsetY = WorldSizeY / 2.0f;
	TArray<AMazeWall*> Agrupaciones;
	int counter = 0;
	int num = FMath::RandRange(0, 7);
	bool bsize = (Quadrants[num].Num() >= 10);
	if (bsize)
	{
		for (int i = 0; i < 10; i++)
		{
			FVector NewLocation = FVector(FMath::RandRange(-OffsetX, OffsetX), FMath::RandRange(-OffsetY, OffsetY), 250.0f);
			Quadrants[num][i]->SetActorLocation(NewLocation, true);
			UE_LOG(LogTemp, Warning, TEXT("Muro teletransportado..."));
		}
	}
}