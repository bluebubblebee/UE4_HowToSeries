// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemToSwap.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItemToSwap::AItemToSwap()
{
	// Declared sub default objects
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Representation
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;

}


void AItemToSwap::BeginPlay()
{
	Super::BeginPlay();

	bIsMoving = false;
	
}

// Called every frame
void AItemToSwap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsMoving) return;

	if (CurrentBezierTime < TotalBezierTime)
	{
		// Calculate location based on bezier curve on a specific point in time
		FVector NewLocation = CalculateBezierCurvePoint(StartLocation, BezierControlPoint, TargetLocation, CurrentBezierTime / TotalBezierTime);

		SetActorLocation(NewLocation);

		// Update currentTime
		CurrentBezierTime += DeltaTime;
	}
	else
	{
		// Move completed
		SetActorLocation(TargetLocation);

		CurrentBezierTime = 0.0f;
		bIsMoving = false;

		// Raise onSwapCompleted event
		OnSwapCompletedEvent.Broadcast();
	}
}



void AItemToSwap::Animate(FVector TargetLoc, float TotalTime)
{
	bIsMoving = false;

	TargetLocation = TargetLoc;

	TotalBezierTime = TotalTime;

	StartLocation = GetActorLocation();

	// Calculate the bezier control point in X direction

	if (TargetLocation.X > StartLocation.X) // Top bezier control point
	{
		float distance = TargetLocation.X - StartLocation.X;

		// Change this values to change the curve 
		float offsetX = distance / 2.0f;
		float offsetY = distance / 2.0f;

		BezierControlPoint = FVector(StartLocation.X + offsetX, StartLocation.Y + offsetY, StartLocation.Z);
	}
	else // bottom bezier control point
	{
		float distance = StartLocation.X - TargetLocation.X;

		// Change this values to change the curve 
		float offsetX = distance / 2.0f;
		float offsetY = distance / 2.0f;;

		BezierControlPoint = FVector(StartLocation.X - offsetX, StartLocation.Y - offsetY, StartLocation.Z);
	}

	CurrentBezierTime = 0.0f;

	// Start moving
	bIsMoving = true;
}


// Calculates location based on 1 control point
// More info: https://javascript.info/bezier-curve
FVector AItemToSwap::CalculateBezierCurvePoint(FVector Start, FVector Control, FVector End, float time)
{
	return (((1 - time) * (1 - time)) * Start) + (2 * time * (1 - time) * Control) + ((time * time) * End);
}

