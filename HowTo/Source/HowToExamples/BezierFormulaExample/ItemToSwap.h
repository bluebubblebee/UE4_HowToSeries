// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemToSwap.generated.h"

// Event Delegate, no paramenters
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwapItemCompletedDelegate);

UCLASS()
class HOWTOEXAMPLES_API AItemToSwap : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemToSwap")
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ItemToSwap")
		class UStaticMeshComponent* Mesh;

public:

	AItemToSwap();

	// Declare and event delegate
	FSwapItemCompletedDelegate OnSwapCompletedEvent;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	void Animate(FVector TargetLoc, float TotalTime);

private:

	bool bIsMoving = false;

	FVector StartLocation;
	FVector TargetLocation;
	FVector BezierControlPoint;

	float CurrentBezierTime = 0.0f;
	float TotalBezierTime = 0.0f;

	FVector CalculateBezierCurvePoint(FVector Start, FVector Control, FVector End, float time);

};
