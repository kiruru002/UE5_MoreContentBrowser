// copyright 2024 kiruru002.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MoreContentBrowserSettings.generated.h"

/**
 * 
 */
UCLASS(config = EditorPerProjectUserSettings)
class MORECONTENTBROWSERMODULE_API UMoreContentBrowserSettings : public UObject
{
	GENERATED_BODY()
	
public:

	UMoreContentBrowserSettings();

	UPROPERTY(EditAnywhere, config, Category = "UMoreContentBrowserSettings", meta = (ConfigRestartRequired = true, ClampMin = "0", ClampMax = "5"))
	int32 AdditionalContentBrowserNum;

};
