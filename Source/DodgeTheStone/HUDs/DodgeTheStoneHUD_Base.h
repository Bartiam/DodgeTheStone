// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DodgeTheStoneHUD_Base.generated.h"

class UPlayerInterface_Base;
class UGameOverWidget_Base;

UCLASS()
class DODGETHESTONE_API ADodgeTheStoneHUD_Base : public AHUD
{
	GENERATED_BODY()
	
public:

	// Classes
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UPlayerInterface_Base> UIDiringTheGameClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf <UGameOverWidget_Base> UIGameOverClass;

private:
	// Private Variables
	UPROPERTY()
	UUserWidget* UIDuringTheGame;

protected:
	virtual void BeginPlay() override;

public:
	// Functions
	UFUNCTION()
	void AddDuringTheGameWidget();

	UFUNCTION()
	void CreateGameOverWidget();
};
