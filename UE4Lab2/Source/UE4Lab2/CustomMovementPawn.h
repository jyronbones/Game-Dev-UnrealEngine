// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimplePawn.h"
#include "CustomMovementPawn.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB2_API ACustomMovementPawn : public ASimplePawn
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	class UCustomMovementComponent* SimpleMovementComponent;

	ACustomMovementPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(float Amount) override;

	virtual void MoveRight(float Amount) override;

};
