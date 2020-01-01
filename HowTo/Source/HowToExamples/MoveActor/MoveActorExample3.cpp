// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActorExample3.h"
#include "Components/StaticMeshComponent.h"

AMoveActorExample3::AMoveActorExample3()
{
	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;

}

void AMoveActorExample3::BeginPlay()
{
	Super::BeginPlay();

	if (Target != nullptr)
	{
		StartLocation = GetActorLocation();

		Direction = Target->GetActorLocation() - StartLocation;

		TotalDistance = Direction.Size();

		UE_LOG(LogTemp, Warning, TEXT("AMoveActorExample3 TotalDistance = %f"), TotalDistance);

		// Get Normal Direction
		Direction = Direction.GetSafeNormal();
		CurrentDistance = 0.0f;
	}
	
}


void AMoveActorExample3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		if (CurrentDistance < TotalDistance)
		{
			FVector Location = GetActorLocation();

			Location += Direction * Speed * DeltaTime;

			SetActorLocation(Location);

			CurrentDistance = (Location - StartLocation).Size();
		}

	}

}

