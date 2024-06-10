// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartsType.h"
#include "GameFramework/Actor.h"
#include "PartsBase.generated.h"



UCLASS()
class EHPROJECT_API APartsBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APartsBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ID")
	FGuid UniqueID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
	PartsType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parts")
	AActor* LeftPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parts")
	AActor* RightPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectedArray")
	TArray<APartsBase*> ConnectedLines;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectedArray")
	TArray<APartsBase*> ConnectedResistors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectedArray")
	APartsBase* ConnectedVoltageSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
	int Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value")
	bool SwitchValue;
private:
	// Function to generate a unique ID
	void GenerateUniqueID();
};
