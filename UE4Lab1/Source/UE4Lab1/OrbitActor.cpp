// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitActor.h"

AOrbitActor::AOrbitActor()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AOrbitActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (RotateAroundActor) {
        CurrentAngle += RotationSpeed * DeltaTime;

        if (CurrentAngle > 360.0f) {
            CurrentAngle -= 360.0f;
        }

        FVector NewLocation = RotateAroundActor->GetActorLocation() + RotationRadius.RotateAngleAxis(CurrentAngle, RotationAxis);

        SetActorLocationAndRotation(NewLocation, FRotator(0.0f, CurrentAngle, 0.0f));

    }
}

void AOrbitActor::BeginPlay()
{
	Super::BeginPlay();

    Reset();
}

void AOrbitActor::Reset()
{
    CurrentAngle = InitialRotationAngle;

    if (!RotateAroundActor) {
        return;
    }

    if (FMath::IsNearlyZero(RotationRadius.Size(), SMALL_NUMBER))
    {
        RotationRadius = GetActorLocation() - RotateAroundActor->GetActorLocation();
    }
}