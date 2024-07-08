// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Moving") // make the variable visible in unreal
	FVector platformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Moving")
	float targetDistance = 100;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator rotationVelocity;
	FVector startLocation;

private:
	void RotatePlatform(float DeltaTime);
	void MovePlatform(float DeltaTime);

	float GetDistanceMoved() const; // const func cannot modify class variables
	bool ShouldPlatformReturn() const;
};
