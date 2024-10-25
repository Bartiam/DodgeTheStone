// Fill out your copyright notice in the Description page of Project Settings.


#include "../PlayerControllers/GameplayPlayerController_Base.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

#include "../Character/DodgeTheStoneCharacter_Base.h"
#include "GameFramework/CharacterMovementComponent.h"

void AGameplayPlayerController_Base::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(inputMode);
	SetShowMouseCursor(false);
	
	// Add input mapping context
	if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		subsystem->AddMappingContext(inputMappingContext, 0);
	}

	// Get pawn 
	character = Cast<ADodgeTheStoneCharacter_Base>(GetPawn());
}


void AGameplayPlayerController_Base::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Moving
		enhancedInputComponent->BindAction(moveInput, ETriggerEvent::Triggered, this, &AGameplayPlayerController_Base::CharacterMovement);
		// Look 
		enhancedInputComponent->BindAction(lookInput, ETriggerEvent::Triggered, this, &AGameplayPlayerController_Base::LookingCharacter);
		// Jump
		enhancedInputComponent->BindAction(jumpInput, ETriggerEvent::Triggered, this, &AGameplayPlayerController_Base::Jump);
		enhancedInputComponent->BindAction(jumpInput, ETriggerEvent::Completed, this, &AGameplayPlayerController_Base::StopJumping);
	}
}

void AGameplayPlayerController_Base::CharacterMovement(const FInputActionValue& value)
{
	FVector2D movementVector = value.Get<FVector2D>();

	if (character)
	{
		// find out which way is forward
		const FRotator rotation = GetControlRotation();
		const FRotator yawRotation(0.f, rotation.Yaw, 0.f);

		// get forward vector
		const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
		// get right vector
		const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
		// add movement
		character->AddMovementInput(forwardDirection, movementVector.Y);
		character->AddMovementInput(rightDirection, movementVector.X);
	}
}

void AGameplayPlayerController_Base::LookingCharacter(const FInputActionValue& value)
{
	// input is a Vector2D
	FVector2D lookAxisVector = value.Get<FVector2D>();

	// add yaw and pitch input to controller
	AddYawInput(lookAxisVector.X);
	AddPitchInput(lookAxisVector.Y);
}

void AGameplayPlayerController_Base::Jump()
{
	if (character)
		character->Jump();
}

void AGameplayPlayerController_Base::StopJumping()
{
	if (character)
		character->StopJumping();
}
