// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPongBall.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMyPongBall::AMyPongBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	RootComponent = BallMesh;
    ballSpeed = 1000.0f;

    UProjectileMovementComponent* BallMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallMovementComponent"));
    BallMovementComponent->InitialSpeed = ballSpeed;
    BallMovementComponent->MaxSpeed = ballSpeed;
    BallMovementComponent->bShouldBounce = true;
    BallMovementComponent->Bounciness = 1.0f;
    BallMovementComponent->Friction = 0.0f;
    BallMovementComponent->ProjectileGravityScale = 0.0f;
    BallMovementComponent->UpdatedComponent = RootComponent;

    // Bind the collision function
    BallMesh->OnComponentHit.AddDynamic(this, &AMyPongBall::OnHit);
}

// Called when the game starts or when spawned
void AMyPongBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPongBall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    UProjectileMovementComponent* BallMovementComponent = Cast<UProjectileMovementComponent>(HitComponent);
    if (BallMovementComponent)
    {
        BallMovementComponent->Velocity.X *= -1.0f;
    }
}

void AMyPongBall::ResetPongBall()
{
    // Reset ball position.
    SetActorLocation(FVector(0.0f, 0.0f, 0.0f));

    // Find the ball's movement component.
    UProjectileMovementComponent* BallMovementComponent = FindComponentByClass<UProjectileMovementComponent>();
    if (BallMovementComponent)
    {
        // Set a new random direction for the ball, ensuring it stays in the 2D plane (X and Y axis).
        FVector RandomDirection = FMath::VRand().GetSafeNormal2D();
        BallMovementComponent->Velocity = RandomDirection * ballSpeed;
    }
}

