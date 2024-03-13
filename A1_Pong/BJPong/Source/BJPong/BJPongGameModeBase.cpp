#include "BJPongGameModeBase.h"
#include <UMG.h>

ABJPongGameModeBase::ABJPongGameModeBase()
{
    Player1Score = 0;
    Player2Score = 0;
}

void ABJPongGameModeBase::BeginPlay()
{
    Super::BeginPlay();

}
void ABJPongGameModeBase::PlayerScored(EPlayer ScoringPlayer)
{
    if (ScoringPlayer == EPlayer::Player)
    {
        Player1Score++;
    }
    else if (ScoringPlayer == EPlayer::AI)
    {
        Player2Score++;
    }
    // Update the UI widget with the new scores.
    UpdateScoreWidget();
}

int32 ABJPongGameModeBase::GetPlayer1Score() const
{
    return Player1Score;
}

int32 ABJPongGameModeBase::GetPlayer2Score() const
{
    return Player2Score;
}

void ABJPongGameModeBase::UpdateScoreWidget()
{
    if (GEngine)
    {
        FString Player1ScoreText = FString::Printf(TEXT("Player 1 Score: %d"), Player1Score);
        FString Player2ScoreText = FString::Printf(TEXT("Player 2 Score: %d"), Player2Score);

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Player1ScoreText);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Player2ScoreText);
    }
}