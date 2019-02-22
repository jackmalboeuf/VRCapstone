// Fill out your copyright notice in the Description page of Project Settings.

#include "UMoveItemComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UUMoveItemComponent::UUMoveItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUMoveItemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUMoveItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*float NewZ = FMath::Asin(DeltaTime / 1000) + GetOwner()->GetActorLocation().Z;
	FVector NewLocation = FVector(GetOwner()->GetActorLocation().X, GetOwner()->GetActorLocation().Y, NewZ);
	GetOwner()->SetActorLocation(NewLocation);*/
	FRotator NewRotation = GetOwner()->GetActorRotation();
	FVector NewLocation = GetOwner()->GetActorLocation();

	NewRotation.Yaw += 1.0f;

	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	RunningTime += DeltaTime;

	GetOwner()->SetActorLocation(NewLocation);
	GetOwner()->SetActorRotation(NewRotation);

	// ...
}

