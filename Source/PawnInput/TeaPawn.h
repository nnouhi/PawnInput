// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TeaBag.h"
#include "TeaPawn.generated.h"


class UCameraComponent;
class USpringArmComponent;


UCLASS()
class PAWNINPUT_API ATeaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATeaPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

private:
	//Component initialization
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* TeapotMesh;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATeaBag> TeabagClass;
			
	//Used for teapot
	UPROPERTY(EditAnywhere,Category="MoveSpeed")
		float MoveSpeed = 200.0f;
	UPROPERTY(EditAnywhere,Category="RotationSpeed")
		float RotationSpeed = 100.0f;

	FVector DeltaLocation;
	FQuat DeltaRotation;

	//Used for camera
	//Camera Location
	UPROPERTY(EditAnywhere, Category = "Camera Location")
		float Camera_X = -400.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Location")
		float Camera_Y = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Location")
		float Camera_Z = 350.0f;
	
	//Camera Rotation
	UPROPERTY(EditAnywhere, Category = "Camera Rotation")
		float InPitch = 0.0;
	UPROPERTY(EditAnywhere, Category = "Camera Rotation")
		float InYaw = -20.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Rotation")
		float InRoll = 0.0f;

	
	//Methods for pawn movement
	void SetMoveAmount(float Value);
	void SetRotateAmount(float Value);
	void SetStrafeAmount(float Value);

	//Methods for pawn shooting
	void OnBeginFire();
	void OnEndFire();		
};
