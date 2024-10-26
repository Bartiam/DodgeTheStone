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

void UDodgeTheStoneGameInstance_Base::SetHighestScore(const int& value)
{
	if (value > GetHighestScore())
		highestScore = value;
}

int UDodgeTheStoneGameInstance_Base::GetHighestScore() const
{
	return highestScore;
}
