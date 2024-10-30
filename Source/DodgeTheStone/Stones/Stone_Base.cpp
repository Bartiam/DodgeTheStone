// Fill out your copyright notice in the Description page of Project Settings.


#include "../Stones/Stone_Base.h"
#include "../Character/DodgeTheStoneCharacter_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"
#include "../GameInstance/DodgeTheStoneGameInstance_Base.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AStone_Base::AStone_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	SetRootComponent(boxCollision);
	
	stone = CreateDefaultSubobject<UStaticMeshComponent>("Stone");
	stone->SetupAttachment(boxCollision);
}

// Called when the game starts or when spawned
void AStone_Base::BeginPlay()
{
	Super::BeginPlay();
	character = Cast<ADodgeTheStoneCharacter_Base>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	boxCollision->OnComponentHit.AddDynamic(this, &AStone_Base::ReflectionFromTheWallCollision);
	SetDirectionMove();
	DamageSettingDependingOnTheDifficulty();
}

// Called every frame
void AStone_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovementStone(DeltaTime);
}

void AStone_Base::MovementStone(float deltaTime)
{
	float timeSpeed = speed * deltaTime;

	FVector currentDirection = FVector(GetActorForwardVector().X * timeSpeed, GetActorForwardVector().Y * timeSpeed, GetActorForwardVector().Z * timeSpeed);

	AddActorWorldOffset(currentDirection, true);
}

void AStone_Base::SetDirectionMove()
{
	// Get location of character
	if (!IsValid(character))
		return;

	FVector currentPositionOfCharacter = character->GetActorLocation();
	// Get location of this actor
	FVector currentPositionOfStone = GetActorLocation();
	// Set rotation this actor
	FRotator lookAt = UKismetMathLibrary::FindLookAtRotation(currentPositionOfStone, currentPositionOfCharacter);
	SetActorRotation(FRotator(0.f, lookAt.Yaw, lookAt.Roll));
}

void AStone_Base::ReflectionFromTheWallCollision(UPrimitiveComponent* hitComponent, AActor* otherActor,
	UPrimitiveComponent* otherComponent, FVector normalImpuls, const FHitResult& sweepResult)
{
	if (otherActor->ActorHasTag(FName("Player")))
	{
		character->healthComponent->TakeDamageFromStone(damage);
		this->Destroy();
		return;
	}

	FVector newDirection = UKismetMathLibrary::GetReflectionVector(GetActorForwardVector(), sweepResult.Normal);
	newDirection.Normalize();
	SetActorRotation(UKismetMathLibrary::MakeRotFromX(newDirection));
}

void AStone_Base::DamageSettingDependingOnTheDifficulty()
{
	auto currentGameInstance = Cast<UDodgeTheStoneGameInstance_Base>(GetGameInstance());

	EGameDifficulty difficulty = currentGameInstance->GetGameDifficalty();

	switch (difficulty)
	{
	case EGameDifficulty::EEASY:
		damage = 25.f;
		break;
	case EGameDifficulty::ENORMAL:
		damage = 50.f;
		break;
	case EGameDifficulty::EHARD:
		damage = 100.f;
		break;
	}
}