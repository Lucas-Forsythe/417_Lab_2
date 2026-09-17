// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpulseDemoComponent.h"

#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
// Sets default values for this component's properties
UImpulseDemoComponent::UImpulseDemoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UImpulseDemoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UImpulseDemoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UImpulseDemoComponent::ApplyImpulse()
{
	AActor* Owner = GetOwner();

	if (!Owner)
	{
		return;
	}

	ACharacter* Character = Cast<ACharacter>(Owner);

	if (!Character)
	{
		return;
	}

	APlayerController* PlayerController =
		Cast<APlayerController>(Character->GetController());

	if (!PlayerController)
	{
		return;
	}

	FVector CameraLocation;
	FRotator CameraRotation;

	PlayerController->GetPlayerViewPoint(
		CameraLocation,
		CameraRotation
	);

	FVector ForwardDirection =
		CameraRotation.Vector();

	FVector TraceEnd =
		CameraLocation +
		(ForwardDirection * InteractionDistance);

	FHitResult Hit;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Owner);

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		Hit,
		CameraLocation,
		TraceEnd,
		ECC_Visibility,
		QueryParams
	);

	DrawDebugLine(
		GetWorld(),
		CameraLocation,
		TraceEnd,
		FColor::Red,
		false,
		1.0f,
		0,
		2.0f
	);

	if (!bHit)
	{
		return;
	}

	UPrimitiveComponent* HitComponent =
		Hit.GetComponent();

	if (!HitComponent)
	{
		return;
	}

	if (!HitComponent->IsSimulatingPhysics())
	{
		return;
	}

	HitComponent->AddImpulse(
		ForwardDirection * ImpulseStrength,
		NAME_None,
		true
	);
}

