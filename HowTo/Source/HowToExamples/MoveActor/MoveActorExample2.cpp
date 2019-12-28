// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActorExample2.h"
#include "Components/StaticMeshComponent.h"

AMoveActorExample2::AMoveActorExample2()
{

	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
}



void AMoveActorExample2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();

	CurrentVelocity += AccelerationRate * DeltaTime;

	Location += GetActorForwardVector() * CurrentVelocity;

	SetActorLocation(Location);

}

