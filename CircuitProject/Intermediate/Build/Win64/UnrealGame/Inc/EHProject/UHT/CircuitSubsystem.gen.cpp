// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EHProject/CircuitSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCircuitSubsystem() {}
// Cross Module References
	EHPROJECT_API UClass* Z_Construct_UClass_APartsBase_NoRegister();
	EHPROJECT_API UClass* Z_Construct_UClass_UCircuitSubsystem();
	EHPROJECT_API UClass* Z_Construct_UClass_UCircuitSubsystem_NoRegister();
	EHPROJECT_API UEnum* Z_Construct_UEnum_EHProject_PartsType();
	EHPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FResultStruct();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_EHProject();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ResultStruct;
class UScriptStruct* FResultStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ResultStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ResultStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FResultStruct, (UObject*)Z_Construct_UPackage__Script_EHProject(), TEXT("ResultStruct"));
	}
	return Z_Registration_Info_UScriptStruct_ResultStruct.OuterSingleton;
}
template<> EHPROJECT_API UScriptStruct* StaticStruct<FResultStruct>()
{
	return FResultStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FResultStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fromx_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_fromx;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fromy_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_fromy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tox_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_tox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_toy_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_toy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_switchValue_MetaData[];
#endif
		static void NewProp_switchValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_switchValue;
		static const UECodeGen_Private::FBytePropertyParams NewProp_type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_type;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FResultStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FResultStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromx_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromx = { "fromx", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, fromx), METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromx_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromx_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromy_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromy = { "fromy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, fromy), METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromy_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromy_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_tox_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_tox = { "tox", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, tox), METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_tox_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_tox_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_toy_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_toy = { "toy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, toy), METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_toy_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_toy_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_value_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, value), METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_value_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue_SetBit(void* Obj)
	{
		((FResultStruct*)Obj)->switchValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue = { "switchValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FResultStruct), &Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type_MetaData[] = {
		{ "Category", "ResultStruct" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FResultStruct, type), Z_Construct_UEnum_EHProject_PartsType, METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type_MetaData)) }; // 2564172177
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FResultStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_fromy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_tox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_toy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_switchValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResultStruct_Statics::NewProp_type,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FResultStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_EHProject,
		nullptr,
		&NewStructOps,
		"ResultStruct",
		sizeof(FResultStruct),
		alignof(FResultStruct),
		Z_Construct_UScriptStruct_FResultStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FResultStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResultStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FResultStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_ResultStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ResultStruct.InnerSingleton, Z_Construct_UScriptStruct_FResultStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ResultStruct.InnerSingleton;
	}
	DEFINE_FUNCTION(UCircuitSubsystem::execImportCircuit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FResultStruct>*)Z_Param__Result=P_THIS->ImportCircuit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCircuitSubsystem::execUpdateCircuit)
	{
		P_GET_TARRAY(APartsBase*,Z_Param_Parts);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateCircuit(Z_Param_Parts);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCircuitSubsystem::execRunCircuit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<float>*)Z_Param__Result=P_THIS->RunCircuit();
		P_NATIVE_END;
	}
	void UCircuitSubsystem::StaticRegisterNativesUCircuitSubsystem()
	{
		UClass* Class = UCircuitSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ImportCircuit", &UCircuitSubsystem::execImportCircuit },
			{ "RunCircuit", &UCircuitSubsystem::execRunCircuit },
			{ "UpdateCircuit", &UCircuitSubsystem::execUpdateCircuit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics
	{
		struct CircuitSubsystem_eventImportCircuit_Parms
		{
			TArray<FResultStruct> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FResultStruct, METADATA_PARAMS(nullptr, 0) }; // 2497867810
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CircuitSubsystem_eventImportCircuit_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 2497867810
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//---------------------------\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xb7\xef\xbf\xbd-----------------------------\n" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
		{ "ToolTip", "---------------------------\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xb7\xef\xbf\xbd-----------------------------" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCircuitSubsystem, nullptr, "ImportCircuit", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::CircuitSubsystem_eventImportCircuit_Parms), Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics
	{
		struct CircuitSubsystem_eventRunCircuit_Parms
		{
			TArray<float> ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CircuitSubsystem_eventRunCircuit_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCircuitSubsystem, nullptr, "RunCircuit", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::CircuitSubsystem_eventRunCircuit_Parms), Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCircuitSubsystem_RunCircuit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCircuitSubsystem_RunCircuit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics
	{
		struct CircuitSubsystem_eventUpdateCircuit_Parms
		{
			TArray<APartsBase*> Parts;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Parts_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Parts;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::NewProp_Parts_Inner = { "Parts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_APartsBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::NewProp_Parts = { "Parts", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CircuitSubsystem_eventUpdateCircuit_Parms, Parts), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::NewProp_Parts_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::NewProp_Parts,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCircuitSubsystem, nullptr, "UpdateCircuit", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::CircuitSubsystem_eventUpdateCircuit_Parms), Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCircuitSubsystem);
	UClass* Z_Construct_UClass_UCircuitSubsystem_NoRegister()
	{
		return UCircuitSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UCircuitSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCircuitSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_EHProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCircuitSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCircuitSubsystem_ImportCircuit, "ImportCircuit" }, // 3626641721
		{ &Z_Construct_UFunction_UCircuitSubsystem_RunCircuit, "RunCircuit" }, // 2259135291
		{ &Z_Construct_UFunction_UCircuitSubsystem_UpdateCircuit, "UpdateCircuit" }, // 2449317099
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCircuitSubsystem_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CircuitSubsystem.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "CircuitSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCircuitSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCircuitSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCircuitSubsystem_Statics::ClassParams = {
		&UCircuitSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCircuitSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCircuitSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCircuitSubsystem()
	{
		if (!Z_Registration_Info_UClass_UCircuitSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCircuitSubsystem.OuterSingleton, Z_Construct_UClass_UCircuitSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCircuitSubsystem.OuterSingleton;
	}
	template<> EHPROJECT_API UClass* StaticClass<UCircuitSubsystem>()
	{
		return UCircuitSubsystem::StaticClass();
	}
	UCircuitSubsystem::UCircuitSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCircuitSubsystem);
	UCircuitSubsystem::~UCircuitSubsystem() {}
	struct Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ScriptStructInfo[] = {
		{ FResultStruct::StaticStruct, Z_Construct_UScriptStruct_FResultStruct_Statics::NewStructOps, TEXT("ResultStruct"), &Z_Registration_Info_UScriptStruct_ResultStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FResultStruct), 2497867810U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCircuitSubsystem, UCircuitSubsystem::StaticClass, TEXT("UCircuitSubsystem"), &Z_Registration_Info_UClass_UCircuitSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCircuitSubsystem), 3069621148U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_842685810(TEXT("/Script/EHProject"),
		Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CircuitSubsystem_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
