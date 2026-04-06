// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"
#include "SpaceEntity.h"
#include "EnemyPatrolShip.h"
#include "EnemyErraticShip.h"
#include "MazeManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
}

void ANavesLAB01USFXGameMode::BeginPlay()
{
	Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    // Spawn 10 naves y agregar a array
    /*
    for (int32 i = 0; i < 10; i++)
    {
        FVector UbicacionSpawn(-600 + (i * 50), 150 + FMath::Sin(i) * 50, 150);  // Spread inicial
        AEnemigo* NuevaNave = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator);

        if (NuevaNave)
        {
			NuevaNave->bMovimientoAutonomo = true;  // Iniciar movimiento autónomo
            AEnemigos.Add(NuevaNave);
            UE_LOG(LogTemp, Warning, TEXT("Nave %d spawnada"), i);
        }
    }*/
    for (int32 i = 0; i < 6; i++)
    {
        FVector SpawnLocation(FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(-1000.0f, 1000.0f), 300.0f);
        if (i < 2)
        {
            ASpaceEntity* NewEnemy = World->SpawnActor<ASpaceEntity>(ASpaceEntity::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
        }
        else if (i < 4)
        {
            AEnemyPatrolShip* NewEnemy = World->SpawnActor<AEnemyPatrolShip>(AEnemyPatrolShip::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
        }
        else
        {
            AEnemyErraticShip* NewEnemy = World->SpawnActor<AEnemyErraticShip>(AEnemyErraticShip::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
        }
    }

    AMazeManager* Mazemanagerr = World->SpawnActor<AMazeManager>(AMazeManager::StaticClass(), FVector(0.0f, 0.0f, 230.0f), FRotator::ZeroRotator);


    
    // Obtener Pawn jugador
    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    
    // Iniciar timer cada 5 seg
    GetWorldTimerManager().SetTimer(TimerFormacion, this, &ANavesLAB01USFXGameMode::FormarNavesFrentePawn, IntervaloFormacion, true);
    
}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
}

void ANavesLAB01USFXGameMode::FormarNavesFrentePawn()
{
    if (!PlayerPawn || AEnemigos.Num() == 0) 
        return;

    FVector UbicacionPawn = PlayerPawn->GetActorLocation();
    FRotator RotacionPawn = PlayerPawn->GetActorRotation();

    // Posición delante del Pawn (offset frontal)
    FVector DireccionFrente = RotacionPawn.Vector();
    FVector PosicionBase = UbicacionPawn + (DireccionFrente * -500);  // 500uu delante

    // Formar verticalmente
    for (int32 i = 0; i < AEnemigos.Num(); i++)
    {
        if (AEnemigo* Nave = AEnemigos[i])
        {
            // Interpolar suavemente a posición de formación
            FVector PosicionFormacion(PosicionBase.X, PosicionBase.Y + (i * EspaciadoVertical), PosicionBase.Z);
			Nave->PosicionDestinoGameMode = PosicionFormacion;
            //Nave->SetActorLocation(FMath::VInterpTo(Nave->GetActorLocation(), PosicionFormacion, GetWorld()->GetDeltaSeconds(), 2.0f));
            Nave->SetActorRotation(FRotator(0, 0, RotacionPawn.Pitch));  // Miran igual que Pawn
			Nave->bMovimientoAutonomo = false;  // Pausar movimiento autónomo
        }
    }

        UE_LOG(LogTemp, Warning, TEXT("¡Naves formadas frente al jugador!"));

    /*if (!PlayerPawn) return;
    FVector UbicacionJugador = PlayerPawn->GetActorLocation();
    FRotator RotacionJugador = PlayerPawn->GetActorRotation();
    for (int32 i = 0; i < AEnemigos.Num(); i++)
    {
        if (AEnemigos[i])
        {
            float DesplazamientoY = (i - AEnemigos.Num() / 2) * EspaciadoVertical;
            FVector NuevaUbicacion = UbicacionJugador + RotacionJugador.RotateVector(FVector(200, DesplazamientoY, 0));
            AEnemigos[i]->SetActorLocation(NuevaUbicacion);
        }
	}*/
}


