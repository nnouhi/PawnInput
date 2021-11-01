// Fill out your copyright notice in the Description page of Project Settings.


#include "TeaBag.h"
#include "Saucer.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
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

	TeabagMesh->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void ATeaBag::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ATeaBag::OnHit);
}

// Called every frame
void ATeaBag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeaBag::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (IsValid(OtherActor))
	{
		if (OtherActor->GetClass()->IsChildOf(ASaucer::StaticClass()))
		{
			if (AActor* ProjectileOwner = GetOwner())
			{
				UGameplayStatics::ApplyDamage(
					OtherActor, //actor that will be damaged
					TeabagDamage, //the base damage to apply
					ProjectileOwner->GetInstigatorController(), //controller that caused the damage
					this, //Actor that actually caused the damage
					UDamageType::StaticClass() //class that describes the damage that was done
				);
				Destroy();
				UE_LOG(LogTemp, Warning, TEXT("Teabag Collided with Soucer"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Nullptr returned"));
			}
		}
	}
	else
	{
		return;
	}
}

