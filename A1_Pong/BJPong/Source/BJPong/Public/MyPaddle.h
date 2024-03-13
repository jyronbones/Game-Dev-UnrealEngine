// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPaddle.generated.h"

class UBoxComponent;
class UMyPawnMovementComponent;

UCLASS()
class BJPONG_API AMyPaddle : public APawn
{
	GENERATED_BODY()

public:
    AMyPaddle();

protected:

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* VisualComponent;

    float ZVelocity;

    UMyPawnMovementComponent* OurMovementComponent;

    virtual UPawnMovementComponent* GetMovementComponent() const override;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


public:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move_ZAxis(float AxisValue);

    float GetZVelocity() const;

};
