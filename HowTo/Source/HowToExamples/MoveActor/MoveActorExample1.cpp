// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActorExample1.h"
#include "Components/StaticMeshComponent.h"


AMoveActorExample1::AMoveActorExample1()
{
	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));	
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;

}

void AMoveActorExample1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	Location += GetActorForwardVector() * Speed * DeltaTime;

	SetActorLocation(Location);
}

