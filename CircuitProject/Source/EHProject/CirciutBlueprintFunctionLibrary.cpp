// Fill out your copyright notice in the Description page of Project Settings.


#include "CirciutBlueprintFunctionLibrary.h"
#include "CircuitSubsystem.h"

UCircuitSubsystem* UCirciutBlueprintFunctionLibrary::GetCircuitSubsystem(UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UWorld* World = WorldContextObject->GetWorld();
	if (!World)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = World->GetGameInstance();
	if (!GameInstance)
	{
		return nullptr;
	}
	return GameInstance->GetSubsystem<UCircuitSubsystem>();
}
