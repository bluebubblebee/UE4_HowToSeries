// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicSplineController.h"
#include "Components/SplineComponent.h"


ABasicSplineController::ABasicSplineController()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Root);
	Spline->Duration = TotalPathTimeController;
	Spline->bDrawDebug = true;



	TotalPathTimeController = 10.0f;
	bCanMoveActor = false;
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicSplineController::BeginPlay()
{
	Super::BeginPlay();
	if (ActorToMoveClass != nullptr)
	{
		ActorToMove = GetWorld()->SpawnActor<AActor>(ActorToMoveClass, Spline->GetComponentTransform());
		if (ActorToMove != nullptr)
		{
			// Time when the press play
			StartTime = GetWorld()->GetTimeSeconds();
			bCanMoveActor = true;

		}
	}
	
}

// Called every frame
void ABasicSplineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Update target
	if ((ActorToMove != nullptr) && (bCanMoveActor))
	{
		float CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;


		float Distance = Spline->GetSplineLength() * CurrentSplineTime;

		// World Position
		FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		ActorToMove->SetActorLocation(Position);


		// World Rotation
		FVector Direction = Spline->GetDirectionAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		// Create rotator given a vector director (normalized)
		FRotator Rotator = FRotationMatrix::MakeFromX(Direction).Rotator();
		ActorToMove->SetActorRotation(Rotator);


		// Reach the end
		if (CurrentSplineTime >= 1.0f)
		{
			if (bSplineInLoop)
			{
				bCanMoveActor = true;

				StartTime = GetWorld()->GetTimeSeconds();

				CurrentSplineTime = (GetWorld()->GetTimeSeconds() - StartTime) / TotalPathTimeController;
			}
		}
	}

}

