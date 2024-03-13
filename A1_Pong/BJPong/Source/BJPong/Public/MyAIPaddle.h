// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyAIPaddle.generated.h"
class AMyPongBall;

UCLASS()
class BJPONG_API AMyAIPaddle : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMyAIPaddle();

protected:
    // Used to detect collisions.
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UBoxComponent* CollisionComponent;

    // Used to show a static mesh and make it visible.
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UStaticMeshComponent* VisualComponent;

    // The AI's movement speed.
    UPROPERTY(EditAnywhere, Category = "AI Settings")
    float AISpeed;

    // Reference to the PongBall to follow.
    UPROPERTY(EditAnywhere, Category = "AI Settings")
    AMyPongBall* myPongBall;

public:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaTime) override;
};