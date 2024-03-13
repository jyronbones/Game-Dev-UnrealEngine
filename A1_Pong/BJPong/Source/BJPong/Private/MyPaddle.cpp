// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaddle.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyPawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AMyPaddle::AMyPaddle()
{
	PrimaryActorTick.bCanEverTick = true;

    AutoPossessPlayer = EAutoReceiveInput::Player0;

    CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("PaddleCollisionComponent"));
    VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleVisualComponent"));

    RootComponent = CollisionComponent;

    VisualComponent->SetupAttachment(CollisionComponent);

    VisualComponent->BodyInstance.SetCollisionProfileName("NoCollision");
    CollisionComponent->BodyInstance.SetCollisionProfileName("Pawn");
    CollisionComponent->OnComponentHit.AddDynamic(this, &AMyPaddle::OnHit);

    ZVelocity = 0.0f;

    OurMovementComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("PaddleCustomMovementComponent"));
    OurMovementComponent->UpdatedComponent = RootComponent;
	
}

UPawnMovementComponent* AMyPaddle::GetMovementComponent() const
{
    return OurMovementComponent;
}

void AMyPaddle::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AMyPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    InputComponent->BindAxis(TEXT("MovePaddle"), this, &AMyPaddle::Move_ZAxis);
}

void AMyPaddle::Move_ZAxis(float Value)
{
    if (Value != 0.0f)
    {
        ZVelocity = Value;

        float Scale = 10000.0f;

        FVector DirectionVector = FVector(Value, 0.0f, 0.0f);

        OurMovementComponent->AddInputVector(DirectionVector * Scale);
    }
}


float AMyPaddle::GetZVelocity() const
{
    return ZVelocity;
}

