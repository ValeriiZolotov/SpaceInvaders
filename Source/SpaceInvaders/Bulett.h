// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Enemy.h"
#include "Bulett.generated.h"


UCLASS()
class SPACEINVADERS_API ABulett : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulett();

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereCollision;

	/*UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;*/

	//Projectile movement component 
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
