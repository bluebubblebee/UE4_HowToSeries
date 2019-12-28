// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActorExample2.generated.h"

UCLASS()
class HOWTOEXAMPLES_API AMoveActorExample2 : public AActor
{
	GENERATED_BODY()

protected:

	// Root component to hold the rest of elements together
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class UStaticMeshComponent* Mesh;

protected:

	UPROPERTY(EditAnywhere, Category = "MoveActor")
	float AccelerationRate = 1.0f;

	float CurrentVelocity = 0.0f;
	
public:	

	AMoveActorExample2();

public:	

	virtual void Tick(float DeltaTime) override;
};
