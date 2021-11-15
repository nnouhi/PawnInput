// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PawnInputGameModeBase_EndLevel.generated.h"

/**
 * 
 */
UCLASS()
class PAWNINPUT_API APawnInputGameModeBase_EndLevel : public AGameModeBase
{
	GENERATED_BODY()

public:
	APawnInputGameModeBase_EndLevel();

private:

	UPROPERTY(EditAnywhere)
	float LevelTimer;

	UPROPERTY(VisibleAnywhere)
	FTimerHandle EndGameTimer;

	UFUNCTION()
	void TimeUp();

	UFUNCTION()
	void StartGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
