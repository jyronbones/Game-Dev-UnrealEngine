// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BJPongGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EPlayer : uint8
{
    Player,
    AI
};
/**
 *
 */
UCLASS()
class BJPONG_API ABJPongGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABJPongGameModeBase();

    void BeginPlay();

    void PlayerScored(EPlayer ScoringPlayer);

    int32 GetPlayer1Score() const;
    int32 GetPlayer2Score() const;

protected:
    int32 Player1Score;
    int32 Player2Score;
    void UpdateScoreWidget();
};