// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CircuitSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APartsBase;
struct FResultStruct;
#ifdef EHPROJECT_CircuitSubsystem_generated_h
#error "CircuitSubsystem.generated.h already included, missing '#pragma once' in CircuitSubsystem.h"
#endif
#define EHPROJECT_CircuitSubsystem_generated_h

#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_50_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FResultStruct_Statics; \
	EHPROJECT_API static class UScriptStruct* StaticStruct();


template<> EHPROJECT_API UScriptStruct* StaticStruct<struct FResultStruct>();

#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_SPARSE_DATA
#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execImportCircuitInFile); \
	DECLARE_FUNCTION(execImportCircuit); \
	DECLARE_FUNCTION(execUpdateCircuit); \
	DECLARE_FUNCTION(execRunCircuit);


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execImportCircuitInFile); \
	DECLARE_FUNCTION(execImportCircuit); \
	DECLARE_FUNCTION(execUpdateCircuit); \
	DECLARE_FUNCTION(execRunCircuit);


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_ACCESSORS
#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCircuitSubsystem(); \
	friend struct Z_Construct_UClass_UCircuitSubsystem_Statics; \
public: \
	DECLARE_CLASS(UCircuitSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EHProject"), NO_API) \
	DECLARE_SERIALIZER(UCircuitSubsystem)


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_INCLASS \
private: \
	static void StaticRegisterNativesUCircuitSubsystem(); \
	friend struct Z_Construct_UClass_UCircuitSubsystem_Statics; \
public: \
	DECLARE_CLASS(UCircuitSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EHProject"), NO_API) \
	DECLARE_SERIALIZER(UCircuitSubsystem)


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCircuitSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCircuitSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCircuitSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCircuitSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCircuitSubsystem(UCircuitSubsystem&&); \
	NO_API UCircuitSubsystem(const UCircuitSubsystem&); \
public: \
	NO_API virtual ~UCircuitSubsystem();


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCircuitSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCircuitSubsystem(UCircuitSubsystem&&); \
	NO_API UCircuitSubsystem(const UCircuitSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCircuitSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCircuitSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCircuitSubsystem) \
	NO_API virtual ~UCircuitSubsystem();


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_76_PROLOG
#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_SPARSE_DATA \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_RPC_WRAPPERS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_ACCESSORS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_INCLASS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_SPARSE_DATA \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_ACCESSORS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_INCLASS_NO_PURE_DECLS \
	FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h_79_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EHPROJECT_API UClass* StaticClass<class UCircuitSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CircuitProject_CircuitProject_Source_EHProject_CircuitSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
