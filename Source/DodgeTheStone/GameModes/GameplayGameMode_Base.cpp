// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameModes/GameplayGameMode_Base.h"
#include "../GameStates/DodgeStoneGameState_Base.h"
#include "../PlayerStates/DodgeStonePlayerState_Base.h"

void AGameplayGameMode_Base::SpawnStone()
{

}

void AGameplayGameMode_Base::BeginPlay()
{
	Super::BeginPlay();

	gameStateDodgeStone = Cast<ADodgeStoneGameState_Base>(GetGameState<ADodgeStoneGameState_Base>());
}

void AGameplayGameMode_Base::Process(const int& currentTime)
{
	if (currentTime % 5 == 0)
	{
		SpawnStone();
		gameStateDodgeStone->SetStoneCount(gameStateDodgeStone->GetStoneCount() + 1);
	}
}

void AGameplayGameMode_Base::EndGame()
{
	gameStateDodgeStone->EndGame();
}

void AGameplayGameMode_Base::RestartGame()
{
	gameStateDodgeStone->RestartGame();
}

void AGameplayGameMode_Base::OnCharacterDied()
{
	
}
