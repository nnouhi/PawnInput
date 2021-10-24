// Fill out your copyright notice in the Description page of Project Settings.


#include "TeaPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
ATeaPawn::ATeaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Set-up Teapot Mesh
	TeapotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teapot Mesh"));
	TeapotMesh->SetupAttachment(RootComponent);

	//Set-up Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(TeapotMesh);
	//how Long the sprint should be
	SpringArm->TargetArmLength = 450.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	//Set-up Camera 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	//Set-up Projectile Spawn Point
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	SpringArm->AttachTo(TeapotMesh);

}

// Called when the game starts or when spawned
void ATeaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATeaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATeaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Drive with W and S
	PlayerInputComponent->BindAxis("Drive", this, &ATeaPawn::SetMoveAmount);
	//Rotate with Mouse X
	PlayerInputComponent->BindAxis("Turn", this, &ATeaPawn::SetRotateAmount);
	//Strafe with A and D
	PlayerInputComponent->BindAxis("Strafe", this, &ATeaPawn::SetStrafeAmount);
	//Shoot with Mouse Left
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATeaPawn::OnBeginFire);
	PlayerInputComponent->BindAction("Fire", IE_Released ,this, &ATeaPawn::OnEndFire);
}

void ATeaPawn::SetMoveAmount(float Value)
{
	DeltaLocation = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	AddActorLocalOffset(DeltaLocation, true);

}

void ATeaPawn::SetRotateAmount(float Value)
{
	FRotator Rotation = FRotator(0.0f, Value * RotationSpeed * GetWorld()->DeltaTimeSeconds, 0.0f);
	DeltaRotation = FQuat(Rotation);
	AddActorLocalRotation(DeltaRotation, true);
}

void ATeaPawn::SetStrafeAmount(float Value)
{
	DeltaLocation = FVector(0.0f, Value * MoveSpeed * GetWorld()->DeltaTimeSeconds,0.0f);
	AddActorLocalOffset(DeltaLocation, true);
}

void ATeaPawn::OnBeginFire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Begin Fire"));
}

void ATeaPawn::OnEndFire()
{
	if (TeabagClass) { //checks teabag projectile has been set in the editor
		//saves the location and rotation information of our teapots ProjectileSpawnPoint
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();

		//spawns the teabag at the location and rotation of our spawn point
		ATeaBag* TempBag = GetWorld()->SpawnActor<ATeaBag>(TeabagClass, SpawnLocation, SpawnRotation);
		TempBag->SetOwner(this);
	}

}






