// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <GameFramework/SpringArmComponent.h>
#include "Camera/CameraComponent.h"
#include "SimplePawn.generated.h"

UCLASS()
class UE4LAB2_API ASimplePawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "My Pawn")
	float Velocity = 0.0f;

	// Sets default values for this pawn's properties
	ASimplePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void UnPossessed() override;

private:
	float MoveForwardAmount = 0.0f;

	float MoveRightAmount = 0.0f;

	virtual void MoveForward(float Amount);

	virtual void MoveRight(float Amount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
