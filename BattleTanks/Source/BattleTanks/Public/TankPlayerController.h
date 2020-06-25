// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	//Start the tank moving the barrel where the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	ATank* GetControlledTank() const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};