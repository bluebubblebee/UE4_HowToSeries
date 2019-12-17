// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OverlapActorExample.generated.h"

UCLASS()
class HOWTOEXAMPLES_API AOverlapActorExample : public AActor
{
	GENERATED_BODY()

protected:

	// Root component to hold the rest of elements together
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OverlapActorExample")
	class USceneComponent* RootScene;

	// Trigger box for collisions
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "OverlapActorExample")
	class UBoxComponent* OverlapCollisionBox;
	
public:	

	AOverlapActorExample();


protected:

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
