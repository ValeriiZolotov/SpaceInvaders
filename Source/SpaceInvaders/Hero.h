// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Hero.generated.h"


class ABulett;
class ASIGameModeBase;

UCLASS()
class SPACEINVADERS_API AHero : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHero();

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereCollision;

	/*UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;*/

	UPROPERTY(EditAnywhere)
		USceneComponent* BulletLocation;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<ABulett> BulletToShoot;

	

	void Shoot();
	void MoveRight(float AxisValue);
	
	//Input variables
	FVector Velocity;
	

	ASIGameModeBase* ModeRef;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
