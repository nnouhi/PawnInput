// Copyright Epic Games, Inc. All Rights Reserved.


#include "PawnInputGameModeBase.h"
#include "Kismet/GameplayStatics.h"



void APawnInputGameModeBase::PointsScored()
{
	PointsCollected += 1;
	UE_LOG(LogTemp, Warning, TEXT("You've Scored, Yours points are: %d"),PointsCollected);
	if (PointsCollected == 10)
	{
		GameOver();
	}
}

void APawnInputGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}

void APawnInputGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Called when game starts"));
}

void APawnInputGameModeBase::GameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Called when game ends"));
	UGameplayStatics::OpenLevel(GetWorld(), "EndGame");

}
