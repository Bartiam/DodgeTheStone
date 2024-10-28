// Fill out your copyright notice in the Description page of Project Settings.


#include "../Character/DodgeTheStoneCharacter_Base.h"
#include "../ActorComponents/HealthComponent_Base.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADodgeTheStoneCharacter_Base::ADodgeTheStoneCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.0f, 0.f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 500.f;
	JumpMaxCount = 2;

	// Create spring arm
	springArm = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArm"));

	springArm->SetupAttachment(RootComponent);
	springArm->SetUsingAbsoluteRotation(true);
	springArm->SocketOffset.Z = 100.f;
	springArm->TargetArmLength = 400.f;
	springArm->bDoCollisionTest = true;
	springArm->bUsePawnControlRotation = true;

	// Create camera
	camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
	camera->bUsePawnControlRotation = true;

	// Create Health component
	healthComponent = CreateDefaultSubobject<UHealthComponent_Base>("Health component");
	Tags.Add(FName("Player"));
}

// Called when the game starts or when spawned
void ADodgeTheStoneCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADodgeTheStoneCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADodgeTheStoneCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADodgeTheStoneCharacter_Base::CharacterDied()
{
	Destroy();
}
