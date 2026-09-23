#include "Projectile.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);

	if (SphereMesh.Succeeded())
	{
		ProjectileMesh->SetStaticMesh(SphereMesh.Object);
	}

	ProjectileMesh->SetSimulatePhysics(true);
	ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ProjectileMesh->SetCollisionProfileName(TEXT("PhysicsActor"));
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(ProjectileLifetime);
}

void AProjectile::LaunchProjectile(FVector Direction)
{
	if (!ProjectileMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("Projectile mesh is missing."));
		return;
	}

	Direction.Normalize();

	ProjectileMesh->AddImpulse(Direction * LaunchStrength, NAME_None, true);
}