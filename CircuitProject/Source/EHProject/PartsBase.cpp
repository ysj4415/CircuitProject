// Fill out your copyright notice in the Description page of Project Settings.


#include "PartsBase.h"

// Sets default values
APartsBase::APartsBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GenerateUniqueID();
}

// Called when the game starts or when spawned
void APartsBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APartsBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APartsBase::GenerateUniqueID()
{
	UniqueID = FGuid::NewGuid();
}

