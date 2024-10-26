// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DodgeTheStoneGameInstance_Base.generated.h"

UENUM(BlueprintType)
enum class EGameDifficulty : uint8
{
	EEASY UMETA(DisplayName = "Easy"), 
	ENORMAL UMETA(DisplayName = "Normal"),
	EHARD UMETA(DisplayName = "Hard")
};

UCLASS()
class DODGETHESTONE_API UDodgeTheStoneGameInstance_Base : public UGameInstance
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	EGameDifficulty currentDifficalty;
	UPROPERTY()
	int highestScore = 0;

public:
	UFUNCTION(BlueprintCallable)
	void SetGameDifficalty(EGameDifficulty gameDifficalty);
	UFUNCTION(BlueprintCallable)
	EGameDifficulty GetGameDifficalty();

	UFUNCTION(BlueprintCallable)
	void SetHighestScore(const int& value);
	UFUNCTION(BlueprintCallable)
	int GetHighestScore() const;
};
