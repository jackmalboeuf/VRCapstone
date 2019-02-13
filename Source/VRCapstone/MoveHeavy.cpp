// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveHeavy.h"


// Sets default values
AMoveHeavy::AMoveHeavy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoveHeavy::BeginPlay()
{
	Super::BeginPlay();
	m_state = Standing;
	m_spawnLocation = GetOwner()->GetActorLocation();
}

// Called every frame
void AMoveHeavy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
}

// Called to bind functionality to input
void AMoveHeavy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

