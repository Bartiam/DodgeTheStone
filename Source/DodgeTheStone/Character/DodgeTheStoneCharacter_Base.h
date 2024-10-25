// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DodgeTheStoneCharacter_Base.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DODGETHESTONE_API ADodgeTheStoneCharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADodgeTheStoneCharacter_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Character camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* springArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* camera;
	// ====================================================================================================== //
};
