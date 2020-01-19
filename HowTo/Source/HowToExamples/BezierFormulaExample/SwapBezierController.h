// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwapBezierController.generated.h"

UCLASS()
class HOWTOEXAMPLES_API ASwapBezierController : public AActor
{
	GENERATED_BODY()
	
public:

	ASwapBezierController();

protected:

	virtual void BeginPlay() override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Swap Controller Settings")
	TSubclassOf<class AItemToSwap> ItemToSwapClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Swap Controller Settings")
		int ItemsToSpawn = 3;

	UPROPERTY(EditAnywhere, Category = "Swap Controller Settings")
		int DistanceBetweenItems = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Swap Controller Settings")
		float SwapTime = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Swap Controller Settings")
		int TotalNumberOfSwaps = 5;


protected:

	UFUNCTION()
	void OnSwapItemCompleted();

private:

	TArray<AItemToSwap*> ItemList;
	TArray<int> ItemIndexList;

	void SwapItems();

	int ItemsToBeSwapped;
	int IndexItemToSwapA;
	int IndexItemToSwapB;

};
