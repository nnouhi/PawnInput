// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PawnInputGameModeBase.generated.h"

UCLASS()
class PAWNINPUT_API APawnInputGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APawnInputGameModeBase();

	UFUNCTION()
		void PointsScored();
	UFUNCTION()
		static void GameOver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void StartGame();
	UFUNCTION()
		void AdvanceNextLevel(const FString& LevelName);
	UFUNCTION()
		void TimeUp();
	UPROPERTY(VisibleAnywhere)
		FTimerHandle EndGameTimer;
	UPROPERTY(VisibleAnywhere, Category = "Game Timer")
		float GameDuration;

	int PointsCollected;
	
};
