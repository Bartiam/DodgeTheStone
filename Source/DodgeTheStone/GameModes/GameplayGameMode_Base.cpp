// Fill out your copyright notice in the Description page of Project Settings.


#include "../GameModes/GameplayGameMode_Base.h"
#include "../GameStates/DodgeStoneGameState_Base.h"
#include "../PlayerStates/DodgeStonePlayerState_Base.h"
#include "../Spawners/Spawner_Base.h"
#include "../HUDs/DodgeTheStoneHUD_Base.h"

#include "Kismet/GameplayStatics.h"

void AGameplayGameMode_Base::SpawnStone()
{
	spawner->SpawnStone();
}

void AGameplayGameMode_Base::BeginPlay()
{
	Super::BeginPlay();

	gameStateDodgeStone = Cast<ADodgeStoneGameState_Base>(GetGameState<ADodgeStoneGameState_Base>());
	gameStateDodgeStone->StartGame();

	spawner = Cast<ASpawner_Base>(UGameplayStatics::GetActorOfClass(GetWorld(), spawnerClass));
}

void AGameplayGameMode_Base::Process(const int& currentTime)
{
	if (currentTime % 2 == 0)
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
	EndGame();
	currentHUD = Cast<ADodgeTheStoneHUD_Base>(UGameplayStatics::GetActorOfClass(GetWorld(), ADodgeTheStoneHUD_Base::StaticClass()));
	currentHUD->CreateGameOverWidget();
}
