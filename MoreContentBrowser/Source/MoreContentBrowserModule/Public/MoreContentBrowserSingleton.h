// copyright 2024 kiruru002.

#pragma once

#include "CoreMinimal.h"

class SContentBrowser;
class FMenuBuilder;
class FSpawnTabArgs;
class FWorkspaceItem;
class SDockTab;
class UToolMenu;
struct FTabSpawnerEntry;

class MORECONTENTBROWSERMODULE_API FMoreContentBrowserSingleton
{
public:
    /** The tab identifier/instance name for content browser tabs */
    TArray<FName> ContentBrowserTabIDs;
    TArray<TSharedPtr<FTabSpawnerEntry>> ContentBrowserTabs;
    TArray<TWeakPtr<SContentBrowser>> AllContentBrowsers;
    TWeakPtr<SContentBrowser> ContentBrowserDrawer;
public:
    FMoreContentBrowserSingleton();
    virtual ~FMoreContentBrowserSingleton();
    TSharedRef<SDockTab> SpawnContentBrowserTab(const FSpawnTabArgs& SpawnTabArgs, int32 BrowserIdx);
    void GetContentBrowserSubMenu(UToolMenu* Menu, TSharedRef<FWorkspaceItem> ContentBrowserGroup);
    FText GetContentBrowserTabLabel(int32 BrowserIdx);
    void ExtendContentBrowserTabContextMenu(FMenuBuilder& InMenuBuilder);
    void FocusContentBrowser(const TSharedPtr<SContentBrowser>& BrowserToFocus);
};
