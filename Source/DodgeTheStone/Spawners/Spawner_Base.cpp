// Fill out your copyright notice in the Description page of Project Settings.


#include "../Spawners/Spawner_Base.h"
#include "../Stones/Stone_Base.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawner_Base::ASpawner_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnCollision = CreateDefaultSubobject<UBoxComponent>(FName("Box Spawn"));
}

// Called when the game starts or when spawned
void ASpawner_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner_Base::SpawnStone()
{
	FVector position = spawnCollision->GetRelativeTransform().GetLocation();
	FVector scale = spawnCollision->GetScaledBoxExtent();

	FVector randomPosition = UKismetMathLibrary::RandomPointInBoundingBox(position, scale);

	FVector positionToSpawn = FVector(randomPosition.X, randomPosition.Y, GetActorLocation().Z);

	GetWorld()->SpawnActor<AStone_Base>(stoneClass, FTransform(positionToSpawn));
}

