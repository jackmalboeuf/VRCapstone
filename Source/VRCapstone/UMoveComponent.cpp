// Fill out your copyright notice in the Description page of Project Settings.

#include "UMoveComponent.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"


// Sets default values for this component's properties
UUMoveComponent::UUMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	spawnLocation = GetOwner()->GetActorLocation();
	// ...
}

void UUMoveComponent::SetLocation()
{
	float x = FMath::RandRange((spawnLocation.X - wanderDistance), (spawnLocation.X + wanderDistance));
	float y = FMath::RandRange((spawnLocation.Y - wanderDistance), (spawnLocation.Y + wanderDistance));
	goalLocation = FVector(x,y, 0);
}

void UUMoveComponent::Move()
{
	
}


// Called every frame
void UUMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	timer -= DeltaTime;

	if (timer <= 0)
	{
		//Change state to Moving
		m_state = Moving;
		timer = moveWaitTime;
	}
	switch (m_state)
	{
	case UUMoveComponent::Moving:
		Move();
		m_state = Standing;
	case UUMoveComponent::Standing:
		break;
	default:
		break;
	}
}

