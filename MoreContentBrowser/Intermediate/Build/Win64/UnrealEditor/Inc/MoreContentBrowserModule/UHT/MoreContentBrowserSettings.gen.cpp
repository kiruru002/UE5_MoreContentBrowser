// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MoreContentBrowserModule/Public/MoreContentBrowserSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMoreContentBrowserSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
MORECONTENTBROWSERMODULE_API UClass* Z_Construct_UClass_UMoreContentBrowserSettings();
MORECONTENTBROWSERMODULE_API UClass* Z_Construct_UClass_UMoreContentBrowserSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_MoreContentBrowserModule();
// End Cross Module References

// Begin Class UMoreContentBrowserSettings
void UMoreContentBrowserSettings::StaticRegisterNativesUMoreContentBrowserSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMoreContentBrowserSettings);
UClass* Z_Construct_UClass_UMoreContentBrowserSettings_NoRegister()
{
	return UMoreContentBrowserSettings::StaticClass();
}
struct Z_Construct_UClass_UMoreContentBrowserSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MoreContentBrowserSettings.h" },
		{ "ModuleRelativePath", "Public/MoreContentBrowserSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalContentBrowserNum_MetaData[] = {
		{ "Category", "UMoreContentBrowserSettings" },
		{ "ClampMax", "5" },
		{ "ClampMin", "0" },
		{ "ConfigRestartRequired", "TRUE" },
		{ "ModuleRelativePath", "Public/MoreContentBrowserSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_AdditionalContentBrowserNum;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMoreContentBrowserSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMoreContentBrowserSettings_Statics::NewProp_AdditionalContentBrowserNum = { "AdditionalContentBrowserNum", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMoreContentBrowserSettings, AdditionalContentBrowserNum), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalContentBrowserNum_MetaData), NewProp_AdditionalContentBrowserNum_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMoreContentBrowserSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMoreContentBrowserSettings_Statics::NewProp_AdditionalContentBrowserNum,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMoreContentBrowserSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMoreContentBrowserSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MoreContentBrowserModule,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMoreContentBrowserSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMoreContentBrowserSettings_Statics::ClassParams = {
	&UMoreContentBrowserSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMoreContentBrowserSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMoreContentBrowserSettings_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMoreContentBrowserSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UMoreContentBrowserSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMoreContentBrowserSettings()
{
	if (!Z_Registration_Info_UClass_UMoreContentBrowserSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMoreContentBrowserSettings.OuterSingleton, Z_Construct_UClass_UMoreContentBrowserSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMoreContentBrowserSettings.OuterSingleton;
}
template<> MORECONTENTBROWSERMODULE_API UClass* StaticClass<UMoreContentBrowserSettings>()
{
	return UMoreContentBrowserSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMoreContentBrowserSettings);
UMoreContentBrowserSettings::~UMoreContentBrowserSettings() {}
// End Class UMoreContentBrowserSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Plugins_MoreContentBrowser_Plugins_MoreContentBrowser_Source_MoreContentBrowserModule_Public_MoreContentBrowserSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMoreContentBrowserSettings, UMoreContentBrowserSettings::StaticClass, TEXT("UMoreContentBrowserSettings"), &Z_Registration_Info_UClass_UMoreContentBrowserSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMoreContentBrowserSettings), 3636725539U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Plugins_MoreContentBrowser_Plugins_MoreContentBrowser_Source_MoreContentBrowserModule_Public_MoreContentBrowserSettings_h_2549878103(TEXT("/Script/MoreContentBrowserModule"),
	Z_CompiledInDeferFile_FID_UE_Plugins_MoreContentBrowser_Plugins_MoreContentBrowser_Source_MoreContentBrowserModule_Public_MoreContentBrowserSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Plugins_MoreContentBrowser_Plugins_MoreContentBrowser_Source_MoreContentBrowserModule_Public_MoreContentBrowserSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
