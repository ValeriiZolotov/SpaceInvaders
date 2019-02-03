// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero.h"
#include "Bulett.h"
#include "Engine/World.h"
#include "SIGameModeBase.h"

// Sets default values
AHero::AHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//Create a scene root 
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	SphereCollision->SetSphereRadius(50.f);
	/*MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));*/
	BulletLocation = CreateDefaultSubobject<USceneComponent>(TEXT("BulletLocation"));

	/*MeshComponent->AttachTo(Root);*/
	SphereCollision->SetupAttachment(Root);
	BulletLocation->SetupAttachment(Root);

	
	

}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
	ModeRef = Cast<ASIGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Handle movement 
	{
		if (!Velocity.IsZero())
		{
			FVector NewLoction = GetActorLocation() + (Velocity*DeltaTime);
			SetActorLocation(NewLoction);
			
		}
	}
}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveRight", this, &AHero::MoveRight);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AHero::Shoot);
}

void AHero::MoveRight(float AxisValue) 
{
	Velocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f)*1000.f;
}

void AHero::Shoot() 
{
	UWorld* World = GetWorld();

	if (World) 
	{
		FVector Location = BulletLocation->GetComponentLocation();
		World->SpawnActor<ABulett>(BulletToShoot, Location, GetActorRotation());
		//UE_LOG(LogTemp, Warning, TEXT("Created"))
		ModeRef->AmmonCounter();
	}
}


