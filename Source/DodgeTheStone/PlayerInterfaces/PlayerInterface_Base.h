// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInterface_Base.generated.h"

UCLASS()
class DODGETHESTONE_API UPlayerInterface_Base : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	class ADodgeTheStoneCharacter_Base* character;
	UPROPERTY()
	class ADodgeStonePlayerState_Base* playerState;

public:
	// Getters
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetCurrentScore();

};
