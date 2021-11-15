// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnInputGameModeBase_EndLevel.h"
#include "Kismet/GameplayStatics.h"
#include "TeaPawn.h"


APawnInputGameModeBase_EndLevel::APawnInputGameModeBase_EndLevel()
{
	LevelTimer = 5.0f;
}
void APawnInputGameModeBase_EndLevel::TimeUp()
{
	UGameplayStatics::OpenLevel(GetWorld(), "FirstLevel");
}

void APawnInputGameModeBase_EndLevel::StartGame()
{
	//Disable Input for pawn
	ATeaPawn* pawnRef = Cast<ATeaPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (IsValid(pawnRef))
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (IsValid(PlayerController))
		{
			pawnRef->DisableInput(PlayerController);
		}
		
	}
	
}

void APawnInputGameModeBase_EndLevel::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &APawnInputGameModeBase_EndLevel::TimeUp, LevelTimer, false);
}
