// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TeaCup.h"
#include "GameFramework/Actor.h"
#include "TeaBag.h"
#include "PawnInputGameModeBase.h"
#include "Saucer.generated.h"

UCLASS()
class PAWNINPUT_API ASaucer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaucer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* SaucerMesh;

	UPROPERTY(EditAnywhere)
		float SoucerHealth;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ASaucer> SaucerSub;
	
	APawnInputGameModeBase* GameMode;


	// declare our float variables
	UPROPERTY(EditAnywhere, Category = Movement)
		float AngleAxis;

	UPROPERTY(EditAnywhere, Category = Movement)
		FVector Dimensions;

	UPROPERTY(EditAnywhere, Category = Movement)
		FVector AxisVector;

	UPROPERTY(EditAnywhere, Category = Movement)
		float Multiplier;

	UFUNCTION()
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
		void RotateSaucer();
};
