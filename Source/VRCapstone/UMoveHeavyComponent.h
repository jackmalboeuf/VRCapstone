// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UMoveHeavyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRCAPSTONE_API UUMoveHeavyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUMoveHeavyComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	enum CharacterState { Standing, Moving, RotatingTowardPlayer, RotatingTowardGoal, Shooting };
	CharacterState m_state;
	FVector m_spawnLocation;
	FVector m_direction;
	FVector m_goalLocation;
	UPROPERTY(EditAnywhere)
		AActor* m_player;
	UPROPERTY(EditAnywhere)
		float m_wanderDistance;
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
	void RotateTowardLocation(float DeltaTime, FVector Location);
	void MoveTowardGoalLocation(float DeltaTime);
	bool CheckRotationIsNearlyZero(float DeltaTime, FVector Location);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
