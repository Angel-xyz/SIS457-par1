// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceEntity.generated.h"

UCLASS()
class NAVESLAB01USFX_API ASpaceEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	UStaticMeshComponent* EntityMesh;

	// Atributos encapsulados
	UPROPERTY(EditAnywhere, Category = "Stats")
	float MovementSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ExecuteBehavior(float DeltaTime);

	float GetMovementSpeed() const { return MovementSpeed; }
	void SetMovementSpeed(float NewSpeed) { MovementSpeed = NewSpeed; }

};
