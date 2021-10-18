// Fill out your copyright notice in the Description page of Project Settings.


#include "GarbageBin.h"

// Sets default values
AGarbageBin::AGarbageBin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GarbageBinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Garbage Bin Mesh"));
	GarbageBinMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGarbageBin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGarbageBin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

