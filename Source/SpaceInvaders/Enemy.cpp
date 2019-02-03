// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Bulett.h"
#include "SIGameModeBase.h"
#include "Hero.h"


class AHero;


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = SceneRoot;

	BoxCollision->SetupAttachment(SceneRoot);

	Direction = FVector(0.f, -1.f, 0.f);
	increment = 0;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AEnemy::SwitchDirection, 4.f, true, 15.f);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);

	ModeRef = Cast<ASIGameModeBase>(GetWorld()->GetAuthGameMode());


}
// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(Direction,DeltaTime);
}


void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	//Cheking if its not ourself who triggered event
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) 
	{
		Destroy();
		ModeRef->KilledEnemy();
		//kill Hero by overlaping with Enemy
		if (OtherActor->IsA(AHero::StaticClass())) 
		{
			OtherActor->Destroy();
			ModeRef->KillHero();
		}
	}
	
}

void AEnemy::SwitchDirection() 
{
	
	UE_LOG(LogTemp, Warning, TEXT("Case: %d"), increment);
	/*switch (increment)
	{
	case 0:
		Direction = FVector(-1.f, 0.f, 0.f);
		//++increment;
	case 1:
		Direction= FVector(0.f, 1.f, 0.f);
		//++increment;
	case 2:
		Direction = FVector(-1.f, 0.f, 0.f);
		++increment;
	case 3:
		Direction = FVector(0.f, 1.f, 0.f);
		
	default:
		break;
	}*/
	if (increment == 0) 
	{
		Direction = FVector(-1.f, 0.f, 0.f);
	}
	else if (increment == 1)
	{
		Direction = FVector(0.f, 1.f, 0.f);
	}
	else if (increment == 2)
	{
		Direction = FVector(-1.f, 0.f, 0.f);
	}
	else if (increment == 3)
	{
		Direction = FVector(0.f, 1.f, 0.f);
	}
	else if (increment == 4)
	{
		Direction = FVector(-1.f, 0.f, 0.f);
	}
	++increment;
	//UE_LOG(LogTemp, Warning, TEXT("X: %d"), Direction.X);
	
	
}

void AEnemy::Move(FVector Direction,float DeltaTime) 
{
	
	FVector Location = GetActorLocation()+(Direction*100*DeltaTime);
	SetActorLocation(Location);
}
