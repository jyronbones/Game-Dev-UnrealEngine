// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPongBall.generated.h"

class UStaticMeshComponent;

UCLASS()
class BJPONG_API AMyPongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPongBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ResetPongBall();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pong Ball", meta = (AllowPrivateAccess = "true"))
	float ballSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pong Ball", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BallMesh;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
