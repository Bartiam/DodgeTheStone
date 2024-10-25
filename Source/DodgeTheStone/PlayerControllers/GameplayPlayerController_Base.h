// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayPlayerController_Base.generated.h"

class UEnhancedInputComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class DODGETHESTONE_API AGameplayPlayerController_Base : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:
	virtual void SetupInputComponent() override;

private:
	FInputModeGameOnly inputMode;
	// current character
	class ADodgeTheStoneCharacter_Base* character;

	// Private functions for movement character
	UFUNCTION()
	void CharacterMovement(const FInputActionValue& value);
	UFUNCTION()
	void LookingCharacter(const FInputActionValue& value);
	UFUNCTION()
	void Jump();
	UFUNCTION()
	void StopJumping();
	// ============================================================================== //

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext* inputMappingContext;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* moveInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* lookInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	UInputAction* jumpInput;
};
