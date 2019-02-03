// Fill out your copyright notice in the Description page of Project Settings.

#include "SIGameModeBase.h"
#include "Kismet/GameplayStatics.h"

class AEnemy;

ASIGameModeBase::ASIGameModeBase() 
{
	PrimaryActorTick.bCanEverTick = true;
	Ammo=450;
	KilledEnemyNumber;
	
	HeroKilled = 0;
	
	Message = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScreenText"));
}


void ASIGameModeBase::BeginPlay() 
{ 
	Super::BeginPlay();

	SpawnEnemy();
	

}
void ASIGameModeBase::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);
	CheckWinner();
}
void ASIGameModeBase::SpawnEnemy() 
{
	UWorld* World = GetWorld();

	if (World)
	{
		FVector Location(1000.f, 600.f, 50.f);
		for (int j{ 0 }; j < 15; ++j) 
		{
			Location.X += -90.f;
			Location.Y = 0.f;
			for (int i{ 0 }; i < 30; ++i)
			{
				Location.Y += 90.f;
				World->SpawnActor<AEnemy>(CreateEnemy, Location, FRotator::ZeroRotator);
				//UE_LOG(LogTemp, Warning, TEXT("Enemy Created"));
				++KilledEnemyNumber; //Getting number of enemies in a scene
			}
		}
	
	}
}
void ASIGameModeBase::KilledEnemy() 
{
	--KilledEnemyNumber;
}
void ASIGameModeBase::AmmonCounter()
{
	--Ammo;
}
void ASIGameModeBase::KillHero()
{
	HeroKilled = 1;
	UE_LOG(LogTemp, Warning, TEXT("HerroKilled"));
}
void ASIGameModeBase::CheckWinner() 
{

	if (HeroKilled == 1) 
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		UE_LOG(LogTemp, Warning, TEXT("Game Paused"));
		Loose();
	}
	else if (Ammo ==0 && KilledEnemyNumber>0) 
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		UE_LOG(LogTemp, Warning, TEXT("Game Paused"));
		Loose();
	}
	else if(HeroKilled!=1 && Ammo>0 && KilledEnemyNumber==0)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		UE_LOG(LogTemp, Warning, TEXT("Game Paused"));
		Win();
	}
}
