// Fill out your copyright notice in the Description page of Project Settings.


#include "../ActorComponents/HealthComponent_Base.h"
#include "../GameModes/GameplayGameMode_Base.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent_Base::UHealthComponent_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	currentHealth = defaultHealth;
}


// Called when the game starts
void UHealthComponent_Base::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UHealthComponent_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHealthComponent_Base::SetCurrentHealth(const float health)
{
	currentHealth = health;
}

float UHealthComponent_Base::GetCurrentHealth() const
{
	return currentHealth;
}

void UHealthComponent_Base::TakeDamageFromStone(const float damage)
{
	SetCurrentHealth(GetCurrentHealth() - damage);

	if (GetCurrentHealth() <= 0.f)
	{
		GetOwner()->Destroy();
		auto gameMode = Cast<AGameplayGameMode_Base>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameplayGameMode_Base::StaticClass()));
		gameMode->OnCharacterDied();
	}
}

void UHealthComponent_Base::SetDeafaultHeatlh(const int& newHealth)
{
	defaultHealth = newHealth;
}

int UHealthComponent_Base::GetDefaultHealth() const
{
	return defaultHealth;
}

