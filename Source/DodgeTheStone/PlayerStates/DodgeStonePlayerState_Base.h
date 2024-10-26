// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DodgeStonePlayerState_Base.generated.h"

/**
 * 
 */
UCLASS()
class DODGETHESTONE_API ADodgeStonePlayerState_Base : public APlayerState
{
	GENERATED_BODY()
	
private:
	int playerScore = 0;

public:
	UFUNCTION()
	void SetPlayerScore(const int& value);
	UFUNCTION()
	int GetPlayerScore() const;
};
