// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActorExample3.generated.h"

UCLASS()
class HOWTOEXAMPLES_API AMoveActorExample3 : public AActor
{
	GENERATED_BODY()
	
protected:

	// Root component to hold the rest of elements together
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class UStaticMeshComponent* Mesh;

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "MoveActor")
		class AActor* Target;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MoveActor")
		float Speed;

public:
	AMoveActorExample3();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:

	FVector Direction;

	float TotalDistance;
	float CurrentDistance;
	FVector StartLocation;

};
