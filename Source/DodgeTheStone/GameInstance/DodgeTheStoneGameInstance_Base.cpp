// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameInstance/DodgeTheStoneGameInstance_Base.h"

void UDodgeTheStoneGameInstance_Base::SetGameDifficalty(EGameDifficulty gameDifficalty)
{
	currentDifficalty = gameDifficalty;
}

EGameDifficulty UDodgeTheStoneGameInstance_Base::GetGameDifficalty()
{
	return currentDifficalty;
}
