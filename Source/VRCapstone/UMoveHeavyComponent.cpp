// Fill out your copyright notice in the Description page of Project Settings.

#include "UMoveHeavyComponent.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"


// Sets default values for this component's properties
UUMoveHeavyComponent::UUMoveHeavyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUMoveHeavyComponent::BeginPlay()
{
	Super::BeginPlay();
	m_state = Standing;
	m_spawnLocation = GetOwner()->GetActorLocation();
	// ...
	
}

void UUMoveHeavyComponent::SetGoalLocation()
{
	float x = FMath::RandRange((m_spawnLocation.X - m_wanderDistance), (m_spawnLocation.X + m_wanderDistance));
	float y = FMath::RandRange((m_spawnLocation.Y - m_wanderDistance), (m_spawnLocation.Y + m_wanderDistance));
	float z = GetOwner()->GetActorLocation().Z;
	m_goalLocation = FVector(x, y, z);

}

void UUMoveHeavyComponent::RotateTowardLocation(float DeltaTime, FVector Location)
{
	/*FRotator newRotation = FRotator(0, m_rotationSpeed * DeltaTime, 0);
	FQuat quatRotation = FQuat(newRotation);
	GetOwner()->AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);*/

	FRotator NewRotation = GetOwner()->GetActorRotation();

	//Determine if m_goalLocation is left or right of actor
	FVector rotationDirection = Location - GetOwner()->GetActorLocation();
	if (rotationDirection.X > 0)
	{
		NewRotation.Yaw += m_rotationSpeed * DeltaTime;
	}
	else
	{
		NewRotation.Yaw -= m_rotationSpeed * DeltaTime;
	}

	GetOwner()->SetActorRotation(NewRotation);
}

void UUMoveHeavyComponent::RotateTowardPlayer(float DeltaTime)
{
}

void UUMoveHeavyComponent::MoveTowardGoalLocation(float DeltaTime)
{
}

bool UUMoveHeavyComponent::CheckRotationIsNearlyZero(FVector Location)
{
	FVector vectorToLocation = Location - GetOwner()->GetActorForwardVector();
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("vectorToLocation.X: %f"), vectorToLocation.X));
	if (FMath::IsNearlyZero(vectorToLocation.X))
	{
		return true;
	}

	return false;
}


// Called every frame
void UUMoveHeavyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	m_timer -= DeltaTime;

	//RotateTowardLocation(DeltaTime, GetOwner()->GetActorLocation());

	switch (m_state)
	{
	case Standing:
		if (m_timer < 0)
		{
			SetGoalLocation();

			if (m_oddsOfShootingInPercent <= 0)
			{
				//TODO move
				m_state = RotatingTowardGoal;
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
		break;
	case Moving:
		break;
	case RotatingTowardGoal:
		RotateTowardLocation(DeltaTime, m_goalLocation);
		if (CheckRotationIsNearlyZero(m_goalLocation))
		{
			m_state = Moving;
		}
		break;
	case RotatingTowardPlayer:
		RotateTowardLocation(DeltaTime, m_player->GetActorLocation());
		if (CheckRotationIsNearlyZero(m_player->GetActorLocation()))
		{
			m_state = Standing;
		}
		break;
	case Shooting:
		break;
	}
}

