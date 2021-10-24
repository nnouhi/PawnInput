// Fill out your copyright notice in the Description page of Project Settings.


#include "Saucer.h"
#include "PawnInputGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASaucer::ASaucer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SaucerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Saucer Mesh"));
	SetRootComponent(SaucerMesh);

	SoucerHealth = 50.0f;
}

// Called when the game starts or when spawned
void ASaucer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaucer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ASaucer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (SoucerHealth > 0.0f)
	{
		SoucerHealth -= DamageAmount;
	}
	else
	{
		Destroy();
		APawnInputGameModeBase::GameOver();
	}
	UE_LOG(LogTemp, Warning, TEXT("Soucers Health: %f"),SoucerHealth);
	return DamageAmount;
}

