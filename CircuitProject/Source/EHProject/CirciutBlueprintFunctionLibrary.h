// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CirciutBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EHPROJECT_API UCirciutBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Subsystem")
	static class UCircuitSubsystem* GetCircuitSubsystem(UObject* WorldContextObject);
};
