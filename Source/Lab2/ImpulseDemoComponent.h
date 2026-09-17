// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ImpulseDemoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LAB2_API UImpulseDemoComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	UImpulseDemoComponent();

	// Applies an impulse to the object the player is looking at
	UFUNCTION(BlueprintCallable)
	void ApplyImpulse();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void TickComponent(
		float DeltaTime,
		ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;

private:

	UPROPERTY(EditAnywhere, Category="Interaction")
	float InteractionDistance = 500.0f;

	UPROPERTY(EditAnywhere, Category="Interaction")
	float ImpulseStrength = 1000.0f;
};
