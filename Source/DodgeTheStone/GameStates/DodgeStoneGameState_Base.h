// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DodgeStoneGameState_Base.generated.h"



UCLASS()
class DODGETHESTONE_API ADodgeStoneGameState_Base : public AGameStateBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	int stoneCount = 0;
	FTimerHandle coreGameTimer;
	int timePlayer = 0;
	// Current game state
	class ADodgeStonePlayerState_Base* playerState;
	// Current game mode
	class AGameplayGameMode_Base* gameMode;
	// Main game instance
	class UDodgeTheStoneGameInstance_Base* gameInstance;

	bool bIsGameEnded;

public:
	// Set the value for stoneCount;
	UFUNCTION(BlueprintCallable)
	void SetStoneCount(const int& value);
	// Get the value from stoneCount;
	UFUNCTION(BlueprintCallable)
	int GetStoneCount() const;
	// Function that ending game;
	UFUNCTION()
	void EndGame();
	// Function that restarting game;
	UFUNCTION()
	void RestartGame();
	// Function that starting game;
	UFUNCTION()
	void StartGame();
	// Updates seconds player and send it to game mode;
	void CoreGameTimerFuntion();
};
