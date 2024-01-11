// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlutoAnimInstance.h"
#include "Characters/PlutoCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UPlutoAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PlutoCharacter = Cast<APlutoCharacter>(TryGetPawnOwner());
	if(PlutoCharacter)
	{
		PlutoCharacterMovement = PlutoCharacter->GetCharacterMovement();
	}
	
}

void UPlutoAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if(PlutoCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(PlutoCharacterMovement->Velocity);
		IsFalling = PlutoCharacterMovement->IsFalling();
	}
}
