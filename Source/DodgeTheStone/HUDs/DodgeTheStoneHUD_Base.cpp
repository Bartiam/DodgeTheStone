// Fill out your copyright notice in the Description page of Project Settings.


#include "../HUDs/DodgeTheStoneHUD_Base.h"
#include "../PlayerInterfaces/PlayerInterface_Base.h"
#include "../PlayerInterfaces/GameOverWidget_Base.h"

void ADodgeTheStoneHUD_Base::BeginPlay()
{
	Super::BeginPlay();

	AddDuringTheGameWidget();
}

void ADodgeTheStoneHUD_Base::AddDuringTheGameWidget()
{
	UIDuringTheGame = CreateWidget(GetOwningPlayerController(), UIDiringTheGameClass);

	UIDuringTheGame->AddToViewport();
}

void ADodgeTheStoneHUD_Base::CreateGameOverWidget()
{
	UIDuringTheGame->RemoveFromParent();

	auto UIGameOverWidget = CreateWidget(GetOwningPlayerController(), UIGameOverClass);

	UIGameOverWidget->AddToViewport();
}
