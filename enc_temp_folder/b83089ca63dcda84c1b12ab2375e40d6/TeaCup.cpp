// Fill out your copyright notice in the Description page of Project Settings.


#include "TeaCup.h"
#include "Components/BoxComponent.h"

// Sets default values
ATeaCup::ATeaCup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TeacupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teacup Mesh"));
	SetRootComponent(TeacupMesh);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision box"));
	CollisionBox->SetupAttachment(TeacupMesh);

	/*Hardcoding (for now) Location and extend of the collision box*/
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 80.0f));
	CollisionBox->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));

	/*Set the UBoxComponents collision profile to ‘Trigger’*/
	CollisionBox->SetCollisionProfileName("Trigger");
}

// Called when the game starts or when spawned
void ATeaCup::BeginPlay()
{
	Super::BeginPlay();
	/*GameModeRef = Cast<APawnInputGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));*/
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATeaCup::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATeaCup::OnOverlapEnd);

}

// Called every frame
void ATeaCup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeaCup::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("On Begin"));
	
}

void ATeaCup::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("On End"));
	
}

