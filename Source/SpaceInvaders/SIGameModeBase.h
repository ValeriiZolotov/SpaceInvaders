// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"
#include "Enemy.h"
#include "SpaceInvaders.h"
#include "Components/TextRenderComponent.h"
#include "SIGameModeBase.generated.h"

class AEnemy;

/**
 * 
 */
UCLASS()
class SPACEINVADERS_API ASIGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASIGameModeBase();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	UTextRenderComponent* Message;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AEnemy> CreateEnemy;

	UPROPERTY(BlueprintReadOnly)
	int Ammo;
	
	UPROPERTY(BlueprintReadOnly)
	int KilledEnemyNumber;

	


	void SpawnEnemy();
	
	void KilledEnemy();
	void AmmonCounter();
	

	int HeroKilled;
	void KillHero();

	void CheckWinner();

	UFUNCTION(BlueprintImplementableEvent)
	void Loose();

	UFUNCTION(BlueprintImplementableEvent)
	void Win();

};
