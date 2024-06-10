// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class PartsType : uint8
{
	Line UMETA(DisplayName = "Line"),
	Resistor UMETA(DisplayName = "Resistor"),
	VoltageSource UMETA(DisplayName = "VoltageSource"),
	Switch UMETA(DisplayName = "Switch")
};