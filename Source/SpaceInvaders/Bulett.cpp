// Fill out your copyright notice in the Description page of Project Settings.

#include "Bulett.h"



// Sets default values
ABulett::ABulett()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereColision"));
	SphereCollision->SetSphereRadius(15.f);
	/*MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));*/
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

	/*MeshComponent->AttachTo(Root);*/
	SphereCollision->SetupAttachment(Root);


}

// Called when the game starts or when spawned
void ABulett::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(1.f);
}

// Called every frame
void ABulett::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

