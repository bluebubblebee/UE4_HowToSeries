// Fill out your copyright notice in the Description page of Project Settings.


#include "SwapBezierController.h"
#include "ItemToSwap.h"

// Sets default values
ASwapBezierController::ASwapBezierController()
{

	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwapBezierController::BeginPlay()
{
	Super::BeginPlay();
	
	// Spawn items to swap
	if (ItemToSwapClass != nullptr)
	{
		FVector Position = GetActorLocation();
		for (int i = 0; i < ItemsToSpawn; i++)
		{
			AItemToSwap* SpawnedItem = GetWorld()->SpawnActor<AItemToSwap>(ItemToSwapClass, Position, FRotator::ZeroRotator);
			if (SpawnedItem != nullptr)
			{
				ItemList.Add(SpawnedItem);

				ItemIndexList.Add(i);

				// Set position 
				Position.X += DistanceBetweenItems;

				// Add event delegate
				ItemList[i]->OnSwapCompletedEvent.AddUniqueDynamic(this, &ASwapBezierController::OnSwapItemCompleted);
			}
		}

		// Start swaping
		SwapItems();
	}
}

void ASwapBezierController::SwapItems()
{
	if (ItemList.Num() == 0) return;

	// Select 2 random items to swap
	int randomIndexA = FMath::RandRange(0, ItemIndexList.Num() - 1);
	int randomIndexB = FMath::RandRange(0, ItemIndexList.Num() - 1);

	while (randomIndexA == randomIndexB)
	{
		randomIndexB = FMath::RandRange(0, ItemIndexList.Num() - 1);
	}


	ItemsToBeSwapped = 2;
	// Get index of items on the
	IndexItemToSwapA = ItemIndexList[randomIndexA];
	IndexItemToSwapB = ItemIndexList[randomIndexB];

	ItemList[IndexItemToSwapA]->Animate(ItemList[IndexItemToSwapB]->GetActorLocation(), SwapTime);
	ItemList[IndexItemToSwapB]->Animate(ItemList[IndexItemToSwapA]->GetActorLocation(), SwapTime);

}

void ASwapBezierController::OnSwapItemCompleted()
{
	ItemsToBeSwapped -= 1;

	if (ItemsToBeSwapped <= 0)
	{
		// Swap them in the list of items
		int tempIndex = ItemIndexList[IndexItemToSwapB];

		ItemIndexList[IndexItemToSwapB] = ItemIndexList[IndexItemToSwapA];

		ItemIndexList[IndexItemToSwapA] = tempIndex;

		TotalNumberOfSwaps--;

		if (TotalNumberOfSwaps > 0)
		{
			// Swap again
			SwapItems();
		}

	}
}