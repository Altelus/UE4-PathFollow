// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PathFollow.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API APathFollow : public AActor
{
public:
	GENERATED_BODY()

		APathFollow(const class FPostConstructInitializeProperties& PCIP);

	UPROPERTY(VisibleInstanceOnly, Category = PathFollow)
		TSubobjectPtr<UBoxComponent> WhereToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PathFollow)
		TArray<FVector> Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PathFollow)
		TArray<FVector> Rotations;

	UFUNCTION(BlueprintPure, Category = PathFollow)
		bool ResetPointsToRandom();

	UFUNCTION(BlueprintPure, Category = PathFollow)
		FVector GetRandomPointInVolume();
};
