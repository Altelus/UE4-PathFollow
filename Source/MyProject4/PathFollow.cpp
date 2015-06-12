// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject4.h"
#include "PathFollow.h"

APathFollow::APathFollow(const class FPostConstructInitializeProperties& PCIP)
	:Super(PCIP)
{
	WhereToSpawn = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("WhereToSpawn"));

	RootComponent = WhereToSpawn;


}
bool APathFollow::ResetPointsToRandom()
{
	Points.Empty();

	for (int i = 0; i < 10; i++)
	{
		Points.Add(GetRandomPointInVolume());

		FRotator SpawnRotation;
		SpawnRotation.Yaw = FMath::FRand() * 360.f;
		SpawnRotation.Pitch = FMath::FRand() * 360.f;
		SpawnRotation.Roll = FMath::FRand() * 360.f;

		Rotations.Add(SpawnRotation.Euler());
	}

	return 1;
}

FVector APathFollow::GetRandomPointInVolume()
{
	FVector RandomLocation;

	float MinX, MinY, MinZ;
	float MaxX, MaxY, MaxZ;

	FVector Origin;
	FVector BoxExtent;

	Origin = WhereToSpawn->Bounds.Origin;
	BoxExtent = WhereToSpawn->Bounds.BoxExtent;

	MinX = Origin.X - BoxExtent.X / 2.f;
	MinY = Origin.Y - BoxExtent.Y / 2.f;
	MinZ = Origin.Z - BoxExtent.Z / 2.f;

	MaxX = Origin.X + BoxExtent.X / 2.f;
	MaxY = Origin.Y + BoxExtent.Y / 2.f;
	MaxZ = Origin.Z + BoxExtent.Z / 2.f;

	RandomLocation.X = FMath::FRandRange(MinX, MaxX);
	RandomLocation.Y = FMath::FRandRange(MinY, MaxY);
	RandomLocation.Z = FMath::FRandRange(MinZ, MaxZ);

	return RandomLocation;
}
