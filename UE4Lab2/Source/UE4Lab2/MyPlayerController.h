// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE4LAB2_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	TArray<AActor*> Pawns;

	int32 CurrentPawnIndex = 0;

	void ChangePawn();

protected:
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

};
