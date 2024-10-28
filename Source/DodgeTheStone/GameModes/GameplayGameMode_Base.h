// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayGameMode_Base.generated.h"

class ADodgeStoneGameState_Base;
class ASpawner_Base;

UCLASS()
class DODGETHESTONE_API AGameplayGameMode_Base : public AGameModeBase
{
	GENERATED_BODY()

private:
	// Get current game state;
	UPROPERTY()
	ADodgeStoneGameState_Base* gameStateDodgeStone;

	// Spawn stone to world;
	UFUNCTION()
	void SpawnStone();

	UPROPERTY()
	ASpawner_Base* spawner;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawner")
	TSubclassOf<ASpawner_Base> spawnerClass;

	// Call function SpawnStone every 5 second;
	UFUNCTION()
	void Process(const int& currentTime);
	// Function for end game
	UFUNCTION()
	void EndGame();
	// Function for restart game;
	UFUNCTION()
	void RestartGame();
	// Function that react for died character;
	UFUNCTION()
	void OnCharacterDied();
};
