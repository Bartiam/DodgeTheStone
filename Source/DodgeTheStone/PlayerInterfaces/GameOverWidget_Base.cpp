// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerInterfaces/GameOverWidget_Base.h"
#include "../GameInstance/DodgeTheStoneGameInstance_Base.h"

void UGameOverWidget_Base::NativeConstruct()
{
	Super::NativeConstruct();

	gameInstance = Cast<UDodgeTheStoneGameInstance_Base>(GetGameInstance());
}

FString UGameOverWidget_Base::GetHighestScore() const
{
	FString result = "The highest score: ";
	result.AppendInt(gameInstance->GetHighestScore());
	return result;
}
