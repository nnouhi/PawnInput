// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeaBag.generated.h"

class UProjectileMovementComponent;

UCLASS()
class PAWNINPUT_API ATeaBag : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeaBag();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	//Used for teabag
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* TeabagMesh;

	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjectileMovement;
		
	UPROPERTY(VisibleAnywhere)
		float MovementSpeed = 1300.0f;

};
