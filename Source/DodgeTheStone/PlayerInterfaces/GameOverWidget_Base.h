// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget_Base.generated.h"

class UDodgeTheStoneGameInstance_Base;

UCLASS()
class DODGETHESTONE_API UGameOverWidget_Base : public UUserWidget
{
	GENERATED_BODY()
	
private:
	virtual void NativeConstruct() override;

	UDodgeTheStoneGameInstance_Base* gameInstance;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString GetHighestScore() const;
};
