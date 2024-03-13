// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGoalArea.h"
#include "MyPongBall.h"
#include "Components/BoxComponent.h"
#include <Kismet/GameplayStatics.h>

AMyGoalArea::AMyGoalArea()
{
    CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyGoalArea::OnGoalEntered);
}

void AMyGoalArea::OnGoalEntered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->IsA(AMyPongBall::StaticClass()))
    {
        // Log a message on the screen
        FString Message = FString::Printf(TEXT("Goal area entered by: %s"),
            (BelongsToPlayer == EPlayer::Player) ? TEXT("Player") : TEXT("AI"));

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);
        }

        // Get a reference to the game mode
        ABJPongGameModeBase* GameMode = Cast<ABJPongGameModeBase>(UGameplayStatics::GetGameMode(this));
        if (GameMode)
        {
            // Update the score
            GameMode->PlayerScored(BelongsToPlayer);
        }

        // Reset the ball's position and velocity
        AMyPongBall* pongBall = Cast<AMyPongBall>(OtherActor);
        if (pongBall)
        {
            pongBall->ResetPongBall();
        }
    }
}