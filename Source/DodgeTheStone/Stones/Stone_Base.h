// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stone_Base.generated.h"

UCLASS()
class DODGETHESTONE_API AStone_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStone_Base();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* stone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float speed = 500.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* boxCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float damage;

	UPROPERTY()
	class ADodgeTheStoneCharacter_Base* character;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void MovementStone(float deltaTime);
	UFUNCTION()
	void SetDirectionMove();
	UFUNCTION()
	void ReflectionFromTheWallCollision(UPrimitiveComponent* hitComponent, AActor* otherActor, 
		UPrimitiveComponent* otherComponent, FVector normalImpuls, const FHitResult& sweepResult);
	UFUNCTION()
	void DamageSettingDependingOnTheDifficulty();

};
