// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

AMovingActor::AMovingActor()
{
    PrimaryActorTick.bCanEverTick = true;
}
	
void AMovingActor::BeginPlay()
{
    Super::BeginPlay();

    MoveToNextPoint();
}

void AMovingActor::MoveToNextPoint()
{
    if (!CurrentPoint || CurrentPoint == SecondPoint)
    {
        CurrentPoint = FirstPoint;
    }
    else
    {
        CurrentPoint = SecondPoint;
    }
}

void AMovingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!FirstPoint || !SecondPoint)
    {
        return;
    }

    if (CurrentPoint)
    {
        FVector Delta = CurrentPoint->GetActorLocation() - GetActorLocation();

        float Distance = Delta.Size();

        if (Distance < 100.0f)
        {
            MoveToNextPoint();
        }

        FVector Direction = Delta.GetSafeNormal();

        FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
        NewLookAt.Pitch = 0.0f;
        NewLookAt.Roll = 0.0f;
        NewLookAt.Yaw += -180.0f;

        SetActorRotation(FMath::Lerp(GetActorRotation(), NewLookAt, 0.03f));
        SetActorLocation(FMath::Lerp(GetActorLocation(), CurrentPoint->GetActorLocation(), 0.03f));
    }
}