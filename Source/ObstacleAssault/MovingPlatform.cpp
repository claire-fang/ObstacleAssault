// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector currentLocation = GetActorLocation();
	currentLocation += platformVelocity * DeltaTime;
	SetActorLocation(currentLocation);
	if (ShouldPlatformReturn()) {
		/*float overshoot = distanceMoved - targetDistance;
		FString name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Overshoot Distance: %f"), *name, overshoot);*/
		FVector direction = platformVelocity.GetSafeNormal();
		startLocation += direction * targetDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved() const
{
	FVector currentLocation = GetActorLocation();
	return FVector::Distance(currentLocation, startLocation);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > targetDistance;
}

