// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameStates/DodgeStoneGameState_Base.h"
#include "../PlayerStates/DodgeStonePlayerState_Base.h"
#include "../GameModes/GameplayGameMode_Base.h"
#include "../GameInstance/DodgeTheStoneGameInstance_Base.h"

#include "Kismet/GameplayStatics.h"

void ADodgeStoneGameState_Base::BeginPlay()
{
	playerState = Cast<ADodgeStonePlayerState_Base>(UGameplayStatics::GetPlayerState(GetWorld(), 0));
	gameMode = Cast<AGameplayGameMode_Base>(UGameplayStatics::GetGameMode(GetWorld()));
	gameInstance = Cast<UDodgeTheStoneGameInstance_Base>(UGameplayStatics::GetGameInstance(GetWorld()));
}

void ADodgeStoneGameState_Base::SetStoneCount(const int& value)
{
	stoneCount = value;
}

int ADodgeStoneGameState_Base::GetStoneCount() const
{
	return stoneCount;
}

void ADodgeStoneGameState_Base::EndGame()
{
	GetWorldTimerManager().ClearTimer(coreGameTimer);
	bIsGameEnded = true;
	gameInstance->SetHighestScore(playerState->GetPlayerScore());

	// Restart game with delay
	FTimerHandle timerToRestart;
	GetWorldTimerManager().SetTimer(timerToRestart, this, &ADodgeStoneGameState_Base::RestartGame, 1.f, false);
}

void ADodgeStoneGameState_Base::RestartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), GetWorld()->GetFName());
}

void ADodgeStoneGameState_Base::StartGame()
{
	bIsGameEnded = false;
	GetWorldTimerManager().SetTimer(coreGameTimer, this, &ADodgeStoneGameState_Base::CoreGameTimerFuntion, 1.f, true);
}

void ADodgeStoneGameState_Base::CoreGameTimerFuntion()
{
	++timePlayer;
	
	if (IsValid(playerState))
	{
		playerState->SetPlayerScore(playerState->GetPlayerScore() + GetStoneCount());
		gameMode->Process(timePlayer);
	}
}
