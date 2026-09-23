// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class LAB2_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float LaunchStrength = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float ProjectileLifetime = 5.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float LaunchCooldown = 0.5f;

	float LastLaunchTime = -1000.0f;

	void LaunchProjectile(FVector Direction);
};
