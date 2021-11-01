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

	Dimensions = FVector(300, 0, 150);
	AxisVector = FVector(0, 0, 1);
	Multiplier = 200.f;
}

// Called every frame
void ASaucer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateSaucer();
	
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

void ASaucer::RotateSaucer()
{
	ATeaCup* myReference = Cast<ATeaCup>(UGameplayStatics::GetActorOfClass(GetWorld(), ATeaCup::StaticClass()));
	GameMode = Cast<APawnInputGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode != NULL)
	{
		if (myReference)
		{
			if (GameMode->GetMapName() == "FirstLevel" || GameMode->GetMapName() == "LastLevel")
			{
				FVector NewLocation = myReference->GetActorLocation();
				AngleAxis += GetWorld()->GetDeltaSeconds() * Multiplier;

				if (AngleAxis >= 360.0f)
				{
					AngleAxis = 0;
				}

				FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

				NewLocation.X += RotateValue.X;
				NewLocation.Y += RotateValue.Y;
				NewLocation.Z += RotateValue.Z;

				FRotator NewRotation = FRotator(40, AngleAxis, 0);

				FQuat QuatRotation = FQuat(NewRotation);

				SetActorLocationAndRotation(NewLocation, QuatRotation, false, 0, ETeleportType::None);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TEST"));
	}
		
}

