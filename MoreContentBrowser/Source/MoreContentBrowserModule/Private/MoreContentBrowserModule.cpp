// copyright 2024 kiruru002.

#include "MoreContentBrowserModule.h"
#include "MoreContentBrowserSingleton.h"
#include "MoreContentBrowserSettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FMoreContentBrowserModule"

void FMoreContentBrowserModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Editor", "Plugins", "MoreContentBrowserPlugin",
			LOCTEXT("SettingName", "MoreContentBrowserPlugin"),
			LOCTEXT("SettingDescription", "MoreContentBrowserPlugin Settings"),
			GetMutableDefault<UMoreContentBrowserSettings>()
		);
	}
	MoreContentBrowserSingleton = new FMoreContentBrowserSingleton();
}

void FMoreContentBrowserModule::ShutdownModule()
{
	if (MoreContentBrowserSingleton)
	{
		delete MoreContentBrowserSingleton;
		MoreContentBrowserSingleton = nullptr;
    }
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Editor", "Plugins", "MoreContentBrowserPlugin");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMoreContentBrowserModule, MoreContentBrowser)
