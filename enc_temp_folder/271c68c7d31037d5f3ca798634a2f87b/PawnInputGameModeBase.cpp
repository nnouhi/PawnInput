// Copyright Epic Games, Inc. All Rights Reserved.


#include "PawnInputGameModeBase.h"



void APawnInputGameModeBase::PointsScored()
{
	UE_LOG(LogTemp, Warning, TEXT("Called"));
}

void APawnInputGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("game mode"));
}

void APawnInputGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Called when game starts"));
}

void APawnInputGameModeBase::GameOver(bool flag)
{
	UE_LOG(LogTemp, Warning, TEXT("Called when game ends"));
}
