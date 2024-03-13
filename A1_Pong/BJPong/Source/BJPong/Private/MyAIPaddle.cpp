#include "MyAIPaddle.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyPongBall.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AMyAIPaddle::AMyAIPaddle()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    // Create and set up the collision component
    CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("PaddleCollisionComponent"));
    VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleVisualComponent"));

    RootComponent = CollisionComponent;

    // Set up CollisionComponent as the parent of VisualComponent;
    VisualComponent->SetupAttachment(CollisionComponent);

    // Disable collisions on Visual Component using "NoCollision" profile.
    VisualComponent->SetCollisionProfileName("NoCollision");
    // Enable collisions on Collision Component using "Pawn" profile.
    CollisionComponent->SetCollisionProfileName("Pawn");

    // Initialize AI paddle speed.
    AISpeed = 500.0f;

    // Find and store a reference to the PongBall.
    myPongBall = nullptr;
    TArray<AActor*> BallActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPongBall::StaticClass(), BallActors);
    if (BallActors.Num() > 0)
    {
        myPongBall = Cast<AMyPongBall>(BallActors[0]);
    }
}

void AMyAIPaddle::BeginPlay()
{
    Super::BeginPlay();
}

void AMyAIPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Get a reference to the PongBall
    if (myPongBall)
    {
        // Calculate the direction vector from the AI paddle to the PongBall
        FVector TargetDirection = myPongBall->GetActorLocation() - GetActorLocation();
        TargetDirection.Z = 0.0f; // Ignore the Z component

        // Normalize the direction vector
        TargetDirection.Normalize();

        // Calculate the new AI paddle location with movement only on the X-axis
        FVector NewLocation = GetActorLocation();
        NewLocation.X += TargetDirection.X * AISpeed * DeltaTime;

        // Update the AI paddle's position
        SetActorLocation(NewLocation);
    }
}