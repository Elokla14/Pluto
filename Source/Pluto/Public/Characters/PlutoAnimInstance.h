// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlutoAnimInstance.generated.h"

class APlutoCharacter;
class UCharacterMovementComponent;

UCLASS()
class PLUTO_API UPlutoAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	APlutoCharacter* PlutoCharacter;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	UCharacterMovementComponent* PlutoCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category= Movement)
	bool IsFalling;
};
