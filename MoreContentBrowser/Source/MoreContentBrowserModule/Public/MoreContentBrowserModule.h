// copyright 2024 kiruru002.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMoreContentBrowserSingleton;

class FMoreContentBrowserModule : public IModuleInterface
{
public:
	FMoreContentBrowserSingleton* MoreContentBrowserSingleton;
	
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
