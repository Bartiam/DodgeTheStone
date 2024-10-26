// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerStates/DodgeStonePlayerState_Base.h"

void ADodgeStonePlayerState_Base::SetPlayerScore(const int& value)
{
	playerScore = value;
}

int ADodgeStonePlayerState_Base::GetPlayerScore() const
{
	return playerScore;
}
