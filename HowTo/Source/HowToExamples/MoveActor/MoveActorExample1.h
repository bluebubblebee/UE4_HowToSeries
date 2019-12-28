// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActorExample1.generated.h"

UCLASS()
class HOWTOEXAMPLES_API AMoveActorExample1 : public AActor
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
	float Speed;

public:	
	AMoveActorExample1();


public:	
	virtual void Tick(float DeltaTime) override;
};
