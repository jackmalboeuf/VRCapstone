// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UMoveHeavyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawnBulletDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRCAPSTONE_API UUMoveHeavyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUMoveHeavyComponent();
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	enum CharacterState { Standing, Moving, RotatingTowardPlayer, RotatingTowardGoal, Shooting };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
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
		float m_originalOddsOfShooting;
	UPROPERTY(EditAnywhere)
		int m_numberOfBulletsToShoot;

		int m_bulletsShot;
	UPROPERTY(EditAnywhere)
		float m_timeBetweenEachBullet;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
		FSpawnBulletDelegate OnShoot;


	void SetGoalLocation();
	void RotateTowardLocation(float DeltaTime, FVector Location);
	void MoveTowardGoalLocation(float DeltaTime);
	bool CheckRotationIsNearlyZero(float DeltaTime, FVector Location);
	void Shoot();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
