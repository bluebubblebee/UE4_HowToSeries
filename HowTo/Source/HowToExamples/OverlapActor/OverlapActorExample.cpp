// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapActorExample.h"
#include "Components/BoxComponent.h"


AOverlapActorExample::AOverlapActorExample()
{
	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create box component and set its root
	OverlapCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapCollisionBox"));
	OverlapCollisionBox->SetupAttachment(RootComponent);


	// Add the dynamic events
	OverlapCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AOverlapActorExample::BeginOverlap);
	OverlapCollisionBox->OnComponentEndOverlap.AddDynamic(this, &AOverlapActorExample::EndOverlap); 
}


void AOverlapActorExample::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SOMETHING HAS ENTERED THE BOX %s"), *OtherActor->GetName());
	}
}


void AOverlapActorExample::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("SOMETHING HAS EXITED THE BOX %s "), *OtherActor->GetName());
	}
}