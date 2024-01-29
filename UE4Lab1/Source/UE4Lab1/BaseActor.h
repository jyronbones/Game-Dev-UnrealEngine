// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class UE4LAB1_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:
	ABaseActor();

	virtual void Tick(float DeltaTime);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Root Component")
		USceneComponent* RootTransformComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Actor Visual")
		UStaticMeshComponent* Mesh;

};
