// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Math/Vector2D.h"
#include "BattleTanks/BattleTanks.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("There is no controlled tank"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank controlled is %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation))
	{
		;
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector CameraWorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *WorldDirection.ToString());
	}

	return true;
}

bool ATankPlayerController::LookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
{

}