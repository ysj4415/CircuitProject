// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PartsType.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EHPROJECT_PartsType_generated_h
#error "PartsType.generated.h already included, missing '#pragma once' in PartsType.h"
#endif
#define EHPROJECT_PartsType_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h


#define FOREACH_ENUM_PARTSTYPE(op) \
	op(PartsType::Line) \
	op(PartsType::Resistor) \
	op(PartsType::VoltageSource) \
	op(PartsType::Switch) 

enum class PartsType : uint8;
template<> struct TIsUEnumClass<PartsType> { enum { Value = true }; };
template<> EHPROJECT_API UEnum* StaticEnum<PartsType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
