// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SimplePawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyPlayerController, All, All)

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind the button press action to switch pawns.
    if (InputComponent)
    {
        // BIND Action "ChangePawn" to the space bar key event when pressed to this object's ChangePawn() function.
        InputComponent->BindAction("ChangePawn", IE_Pressed, this, &AMyPlayerController::ChangePawn);
        UE_LOG(LogMyPlayerController, Warning, TEXT("Input bindings set up successfully."));
    }
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Get all actors of type ASimplePawn in the level.
    TArray<AActor*> FoundPawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASimplePawn::StaticClass(), FoundPawns);

    if (FoundPawns.Num() == 0)
    {
        UE_LOG(LogMyPlayerController, Warning, TEXT("No ASimplePawn instances found in the level."));
    }
    else
    {
        for (AActor* Actor : FoundPawns)
        {
            ASimplePawn* SimplePawn = Cast<ASimplePawn>(Actor);
            if (SimplePawn)
            {
                Pawns.Add(SimplePawn);
            }
        }

        UE_LOG(LogMyPlayerController, Warning, TEXT("Successfully added %d ASimplePawn instances to the array."), Pawns.Num());
    }
}




void AMyPlayerController::ChangePawn()
{
    // Implement the logic to switch pawns in the Pawns array.
    if (Pawns.Num() < 1)
    {
        // Return if there are no pawns in the array.
        UE_LOG(LogMyPlayerController, Warning, TEXT("No pawns in the array to switch to."));
        return;
    }

    // Get the CurrentPawn from the array of Pawns at CurrentPawnIndex.
    APawn* CurrentPawn = Cast<APawn>(Pawns[CurrentPawnIndex]);

    // Set the CurrentPawnIndex to the next Pawn in the Pawns array.
    CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();

    if (!CurrentPawn)
    {
        UE_LOG(LogMyPlayerController, Warning, TEXT("CurrentPawn is null."));
        return;
    }
    // Possess the CurrentPawn.
    Possess(CurrentPawn);

    UE_LOG(LogMyPlayerController, Warning, TEXT("Change Pawn"));
}
