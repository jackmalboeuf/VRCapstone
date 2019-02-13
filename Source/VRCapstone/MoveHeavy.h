// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MoveHeavy.generated.h"

UCLASS()
class VRCAPSTONE_API AMoveHeavy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMoveHeavy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	enum CharacterState { Standing, Moving, Rotating, Shooting};
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
