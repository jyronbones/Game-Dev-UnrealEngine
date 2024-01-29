// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "OrbitActor.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB1_API AOrbitActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AOrbitActor();

	virtual void Tick(float DeltaTime);

	void Reset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
		AActor* RotateAroundActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
		float RotationSpeed = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
		FVector RotationRadius = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
		FVector RotationAxis = FVector::UpVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround")
		float InitialRotationAngle = 0.0f;

protected:

	float CurrentAngle = 0.0f;

	virtual void BeginPlay() override;
};