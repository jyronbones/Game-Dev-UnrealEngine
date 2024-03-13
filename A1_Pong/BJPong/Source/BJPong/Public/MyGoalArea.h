// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BJPong/BJPongGameModeBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGoalArea.generated.h"

UCLASS()
class BJPONG_API AMyGoalArea : public AActor
{
    GENERATED_BODY()

public:
    AMyGoalArea();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Goal Area")
    class UBoxComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Goal Area")
    EPlayer BelongsToPlayer;

    UFUNCTION()
    void OnGoalEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};