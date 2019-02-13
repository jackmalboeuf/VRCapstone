// Fill out your copyright notice in the Description page of Project Settings.

#include "UMoveHeavy.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UUMoveHeavy::UUMoveHeavy()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUMoveHeavy::BeginPlay()
{
	Super::BeginPlay();
	m_state = Standing;
	m_spawnLocation = GetOwner()->GetActorLocation();

	// ...
	
}

void UUMoveHeavy::SetGoalLocation()
{
}

void UUMoveHeavy::RotateTowardGoalLocation(float DeltaTime)
{
	FRotator newRotation = FRotator(0, m_rotationSpeed * DeltaTime, 0);
	FQuat quatRotation = FQuat(newRotation);
	GetOwner()->AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);
}

void UUMoveHeavy::RotateTowardPlayer(float DeltaTime)
{
}

void UUMoveHeavy::MoveTowardGoalLocation(float DeltaTime)
{
}


// Called every frame
void UUMoveHeavy::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	m_timer -= DeltaTime;

	if (m_timer < 0)
	{
		//TODO set target to move to

		if (m_oddsOfShootingInPercent <= 0)
		{
			//TODO move
		}
		else
		{
			if (FMath::RandRange(1, 100) <= m_oddsOfShootingInPercent)
			{
				//TODO shoot and lower m_oddsOfShootingInPercent by m_oddsOfShootingOffset
			}
		}

		m_timer = m_timeBetweenMovingOrShooting;
	}

	switch (m_state)
	{
	case Standing:
		break;
	case Moving:
		break;
	case Rotating:
		break;
	case Shooting:
		break;
	}
	// ...
}

