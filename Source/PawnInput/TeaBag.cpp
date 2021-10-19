// Fill out your copyright notice in the Description page of Project Settings.


#include "TeaBag.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ATeaBag::ATeaBag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TeabagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teabag Mesh"));
	SetRootComponent(TeabagMesh);
	TeabagMesh->SetSimulatePhysics(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->MaxSpeed = MovementSpeed;
	ProjectileMovement->InitialSpeed = MovementSpeed;
	InitialLifeSpan = 5.0f;


}

// Called when the game starts or when spawned
void ATeaBag::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeaBag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

