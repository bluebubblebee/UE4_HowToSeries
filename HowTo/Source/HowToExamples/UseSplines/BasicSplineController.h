// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicSplineController.generated.h"

UCLASS()
class HOWTOEXAMPLES_API ABasicSplineController : public AActor
{

	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
	USceneComponent *Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SplineController")
	class USplineComponent* Spline;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "SplineController")
	TSubclassOf<class AActor> ActorToMoveClass;

	class AActor* ActorToMove;

protected:

	UPROPERTY(EditAnywhere, Category = "SplineController")
	float TotalPathTimeController;

	UPROPERTY(EditAnywhere, Category = "SplineController")
	bool bSplineInLoop;

	bool bCanMoveActor;

	float StartTime;

public:

	ABasicSplineController();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
