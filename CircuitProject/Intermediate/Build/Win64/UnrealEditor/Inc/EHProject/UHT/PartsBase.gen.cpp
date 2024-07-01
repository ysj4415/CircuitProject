// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EHProject/PartsBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePartsBase() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	EHPROJECT_API UClass* Z_Construct_UClass_APartsBase();
	EHPROJECT_API UClass* Z_Construct_UClass_APartsBase_NoRegister();
	EHPROJECT_API UEnum* Z_Construct_UEnum_EHProject_PartsType();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_EHProject();
// End Cross Module References
	void APartsBase::StaticRegisterNativesAPartsBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APartsBase);
	UClass* Z_Construct_UClass_APartsBase_NoRegister()
	{
		return APartsBase::StaticClass();
	}
	struct Z_Construct_UClass_APartsBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UniqueID_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UniqueID;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftPoint_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightPoint_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RightPoint;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ConnectedLines_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedLines_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedLines;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ConnectedResistors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedResistors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ConnectedResistors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ConnectedVoltageSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ConnectedVoltageSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Value;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SwitchValue_MetaData[];
#endif
		static void NewProp_SwitchValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SwitchValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CanRemove_MetaData[];
#endif
		static void NewProp_CanRemove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CanRemove;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APartsBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_EHProject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PartsBase.h" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_UniqueID_MetaData[] = {
		{ "Category", "ID" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_UniqueID = { "UniqueID", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, UniqueID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_UniqueID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_UniqueID_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "Type" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, Type), Z_Construct_UEnum_EHProject_PartsType, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_Type_MetaData)) }; // 2564172177
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_LeftPoint_MetaData[] = {
		{ "Category", "Parts" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_LeftPoint = { "LeftPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, LeftPoint), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_LeftPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_LeftPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_RightPoint_MetaData[] = {
		{ "Category", "Parts" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_RightPoint = { "RightPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, RightPoint), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_RightPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_RightPoint_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines_Inner = { "ConnectedLines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_APartsBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines_MetaData[] = {
		{ "Category", "ConnectedArray" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines = { "ConnectedLines", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, ConnectedLines), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors_Inner = { "ConnectedResistors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_APartsBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors_MetaData[] = {
		{ "Category", "ConnectedArray" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors = { "ConnectedResistors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, ConnectedResistors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedVoltageSource_MetaData[] = {
		{ "Category", "ConnectedArray" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedVoltageSource = { "ConnectedVoltageSource", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, ConnectedVoltageSource), Z_Construct_UClass_APartsBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedVoltageSource_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedVoltageSource_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APartsBase, Value), METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_Value_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	void Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue_SetBit(void* Obj)
	{
		((APartsBase*)Obj)->SwitchValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue = { "SwitchValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(APartsBase), &Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue_SetBit, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "PartsBase.h" },
	};
#endif
	void Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove_SetBit(void* Obj)
	{
		((APartsBase*)Obj)->CanRemove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove = { "CanRemove", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(APartsBase), &Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove_SetBit, METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APartsBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_UniqueID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_Type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_Type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_LeftPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_RightPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedLines,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedResistors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_ConnectedVoltageSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_SwitchValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APartsBase_Statics::NewProp_CanRemove,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APartsBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APartsBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APartsBase_Statics::ClassParams = {
		&APartsBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APartsBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APartsBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APartsBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APartsBase()
	{
		if (!Z_Registration_Info_UClass_APartsBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APartsBase.OuterSingleton, Z_Construct_UClass_APartsBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APartsBase.OuterSingleton;
	}
	template<> EHPROJECT_API UClass* StaticClass<APartsBase>()
	{
		return APartsBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APartsBase);
	APartsBase::~APartsBase() {}
	struct Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APartsBase, APartsBase::StaticClass, TEXT("APartsBase"), &Z_Registration_Info_UClass_APartsBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APartsBase), 911897515U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsBase_h_1951956749(TEXT("/Script/EHProject"),
		Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
