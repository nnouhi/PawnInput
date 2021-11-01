// Copyright Epic Games, Inc. All Rights Reserved.


#include "PawnInputGameModeBase.h"
#include "Kismet/GameplayStatics.h"

APawnInputGameModeBase::APawnInputGameModeBase()
{
	PointsCollected = 0;
	GameDuration = 10.0f;
}
void APawnInputGameModeBase::PointsScored()
{
	
	PointsCollected += 1;

	UE_LOG(LogTemp, Warning, TEXT("You've Scored, Yours points are: %d"),PointsCollected);

	//Debugging 
	/*UE_LOG(LogTemp, Warning, TEXT("Map: %s"), *LevelName);*/

	if (PointsCollected == 10)
	{
		AdvanceNextLevel(GetMapName());
	}
	
}

void APawnInputGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer,this, &APawnInputGameModeBase::TimeUp,GameDuration,false);
}

void APawnInputGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Called when game starts"));
}

void APawnInputGameModeBase::AdvanceNextLevel(const FString& LevelName)
{
	if (LevelName.Equals("FirstLevel"))
	{
		UGameplayStatics::OpenLevel(GetWorld(), "SecondLevel");
	}
	else if (LevelName.Equals("SecondLevel"))
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LastLevel");
	}
	else if (LevelName.Equals("LastLevel"))
	{
		UGameplayStatics::OpenLevel(GetWorld(), "FirstLevel");
	}
	
	
}

void APawnInputGameModeBase::TimeUp()
{
	UE_LOG(LogTemp, Warning, TEXT("Times Up, Unfortunately you lose!"));
}

FString APawnInputGameModeBase::GetMapName()
{
	FString LevelName = GetWorld()->GetMapName();
	//Remove the UEDPIE prefix
	LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);
	return LevelName;
}

void APawnInputGameModeBase::GameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("You Lost!"));
}
