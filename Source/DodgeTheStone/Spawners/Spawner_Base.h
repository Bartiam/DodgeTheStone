// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner_Base.generated.h"

class UBoxComponent;
class AStone_Base;

UCLASS()
class DODGETHESTONE_API ASpawner_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner_Base();

	// Collision of spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Collision")
	UBoxComponent* spawnCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stone")
	TSubclassOf<AStone_Base> stoneClass;

	void SpawnStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Sets private functions for this actor
	
};
