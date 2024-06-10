// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EHProject/CirciutBlueprintFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCirciutBlueprintFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	EHPROJECT_API UClass* Z_Construct_UClass_UCirciutBlueprintFunctionLibrary();
	EHPROJECT_API UClass* Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_NoRegister();
	EHPROJECT_API UClass* Z_Construct_UClass_UCircuitSubsystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_EHProject();
// End Cross Module References
	DEFINE_FUNCTION(UCirciutBlueprintFunctionLibrary::execGetCircuitSubsystem)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCircuitSubsystem**)Z_Param__Result=UCirciutBlueprintFunctionLibrary::GetCircuitSubsystem(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void UCirciutBlueprintFunctionLibrary::StaticRegisterNativesUCirciutBlueprintFunctionLibrary()
	{
		UClass* Class = UCirciutBlueprintFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCircuitSubsystem", &UCirciutBlueprintFunctionLibrary::execGetCircuitSubsystem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics
	{
		struct CirciutBlueprintFunctionLibrary_eventGetCircuitSubsystem_Parms
		{
			UObject* WorldContextObject;
			UCircuitSubsystem* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CirciutBlueprintFunctionLibrary_eventGetCircuitSubsystem_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CirciutBlueprintFunctionLibrary_eventGetCircuitSubsystem_Parms, ReturnValue), Z_Construct_UClass_UCircuitSubsystem_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Subsystem" },
		{ "ModuleRelativePath", "CirciutBlueprintFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCirciutBlueprintFunctionLibrary, nullptr, "GetCircuitSubsystem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::CirciutBlueprintFunctionLibrary_eventGetCircuitSubsystem_Parms), Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCirciutBlueprintFunctionLibrary);
	UClass* Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_NoRegister()
	{
		return UCirciutBlueprintFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_EHProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCirciutBlueprintFunctionLibrary_GetCircuitSubsystem, "GetCircuitSubsystem" }, // 3164270294
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CirciutBlueprintFunctionLibrary.h" },
		{ "ModuleRelativePath", "CirciutBlueprintFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCirciutBlueprintFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::ClassParams = {
		&UCirciutBlueprintFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCirciutBlueprintFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UCirciutBlueprintFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCirciutBlueprintFunctionLibrary.OuterSingleton, Z_Construct_UClass_UCirciutBlueprintFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCirciutBlueprintFunctionLibrary.OuterSingleton;
	}
	template<> EHPROJECT_API UClass* StaticClass<UCirciutBlueprintFunctionLibrary>()
	{
		return UCirciutBlueprintFunctionLibrary::StaticClass();
	}
	UCirciutBlueprintFunctionLibrary::UCirciutBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCirciutBlueprintFunctionLibrary);
	UCirciutBlueprintFunctionLibrary::~UCirciutBlueprintFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CirciutBlueprintFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CirciutBlueprintFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCirciutBlueprintFunctionLibrary, UCirciutBlueprintFunctionLibrary::StaticClass, TEXT("UCirciutBlueprintFunctionLibrary"), &Z_Registration_Info_UClass_UCirciutBlueprintFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCirciutBlueprintFunctionLibrary), 3723607124U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CirciutBlueprintFunctionLibrary_h_1483839455(TEXT("/Script/EHProject"),
		Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CirciutBlueprintFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_eh_EHProject_vol1_Source_EHProject_CirciutBlueprintFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
