// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EHProject/PartsType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePartsType() {}
// Cross Module References
	EHPROJECT_API UEnum* Z_Construct_UEnum_EHProject_PartsType();
	UPackage* Z_Construct_UPackage__Script_EHProject();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_PartsType;
	static UEnum* PartsType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_PartsType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_PartsType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_EHProject_PartsType, (UObject*)Z_Construct_UPackage__Script_EHProject(), TEXT("PartsType"));
		}
		return Z_Registration_Info_UEnum_PartsType.OuterSingleton;
	}
	template<> EHPROJECT_API UEnum* StaticEnum<PartsType>()
	{
		return PartsType_StaticEnum();
	}
	struct Z_Construct_UEnum_EHProject_PartsType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_EHProject_PartsType_Statics::Enumerators[] = {
		{ "PartsType::Line", (int64)PartsType::Line },
		{ "PartsType::Resistor", (int64)PartsType::Resistor },
		{ "PartsType::VoltageSource", (int64)PartsType::VoltageSource },
		{ "PartsType::Switch", (int64)PartsType::Switch },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_EHProject_PartsType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Line.DisplayName", "Line" },
		{ "Line.Name", "PartsType::Line" },
		{ "ModuleRelativePath", "PartsType.h" },
		{ "Resistor.DisplayName", "Resistor" },
		{ "Resistor.Name", "PartsType::Resistor" },
		{ "Switch.DisplayName", "Switch" },
		{ "Switch.Name", "PartsType::Switch" },
		{ "VoltageSource.DisplayName", "VoltageSource" },
		{ "VoltageSource.Name", "PartsType::VoltageSource" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_EHProject_PartsType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_EHProject,
		nullptr,
		"PartsType",
		"PartsType",
		Z_Construct_UEnum_EHProject_PartsType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_EHProject_PartsType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_EHProject_PartsType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_EHProject_PartsType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_EHProject_PartsType()
	{
		if (!Z_Registration_Info_UEnum_PartsType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_PartsType.InnerSingleton, Z_Construct_UEnum_EHProject_PartsType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_PartsType.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h_Statics::EnumInfo[] = {
		{ PartsType_StaticEnum, TEXT("PartsType"), &Z_Registration_Info_UEnum_PartsType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2564172177U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h_2176840324(TEXT("/Script/EHProject"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CircuitProject_CircuitProject_Source_EHProject_PartsType_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
