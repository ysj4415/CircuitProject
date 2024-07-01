// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEHProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_EHProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_EHProject()
	{
		if (!Z_Registration_Info_UPackage__Script_EHProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/EHProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x1CB8C4A3,
				0x09C3B5AD,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_EHProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_EHProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_EHProject(Z_Construct_UPackage__Script_EHProject, TEXT("/Script/EHProject"), Z_Registration_Info_UPackage__Script_EHProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1CB8C4A3, 0x09C3B5AD));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
