// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB1_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AMovingActor();
	
	virtual void Tick(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoints")
		AActor* FirstPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoints")
		AActor* SecondPoint;

private:
	AActor* CurrentPoint;

	void MoveToNextPoint();

protected:

	virtual void BeginPlay() override;
};
