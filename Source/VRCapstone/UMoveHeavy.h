// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UMoveHeavy.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRCAPSTONE_API UUMoveHeavy : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUMoveHeavy();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	enum CharacterState { Standing, Moving, Rotating, Shooting };
	CharacterState m_state;
	FVector m_spawnLocation;
	FVector m_direction;
	FVector m_goalLocation;
	UPROPERTY(EditAnywhere)
		float m_movementSpeed;
	UPROPERTY(EditAnywhere)
		float m_rotationSpeed;
	UPROPERTY(EditAnywhere)
		float m_timeBetweenMovingOrShooting;
	float m_timer;
	UPROPERTY(EditAnywhere)
		float m_oddsOfShootingOffset;
	UPROPERTY(EditAnywhere)
		float m_oddsOfShootingInPercent;
	UPROPERTY(EditAnywhere)
		int m_numberOfBulletsToShoot;

	void SetGoalLocation();
	void RotateTowardGoalLocation(float DeltaTime);
	void RotateTowardPlayer(float DeltaTime);
	void MoveTowardGoalLocation(float DeltaTime);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
