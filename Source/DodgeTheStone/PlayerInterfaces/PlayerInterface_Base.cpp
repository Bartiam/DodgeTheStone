// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerInterfaces/PlayerInterface_Base.h"
#include "../Character/DodgeTheStoneCharacter_Base.h"
#include "../PlayerStates/DodgeStonePlayerState_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"

void UPlayerInterface_Base::NativeConstruct()
{
	Super::NativeConstruct();

	character = Cast<ADodgeTheStoneCharacter_Base>(GetOwningPlayerPawn());
	playerState = Cast<ADodgeStonePlayerState_Base>(GetOwningPlayerState());
}

float UPlayerInterface_Base::GetCurrentHealth()
{
	return character->healthComponent->GetCurrentHealth() * 0.01f;
}

FString UPlayerInterface_Base::GetCurrentScore()
{
	FString result = "Current score: ";
	result.AppendInt(playerState->GetPlayerScore());
	return result;
}
