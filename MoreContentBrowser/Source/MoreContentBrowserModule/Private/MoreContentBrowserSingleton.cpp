// copyright 2024 kiruru002.


#include "MoreContentBrowserSingleton.h"
#include "MoreContentBrowserSettings.h"
#include "Editor.h"
#include "ContentBrowserModule.h"
#include "ContentBrowserSingleton.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "IContentBrowserSingleton.h"
#include "ContentBrowserCommands.h"
#include "ToolMenuSection.h"
#include "SContentBrowser.h"
#include "IDocumentation.h"
#include "TutorialMetaData.h"
#include "StatusBarSubsystem.h"
#include "ToolMenus.h"
#include "ContentBrowserSingleton.h"

#define LOCTEXT_NAMESPACE "MoreContentBrowserSingleton"

namespace
{
    FContentBrowserSingleton& GetContentBrowserSingleton()
    {
        static const FName ModuleName = "ContentBrowser";
        FContentBrowserModule& Module = FModuleManager::GetModuleChecked<FContentBrowserModule>(ModuleName);
        return static_cast<FContentBrowserSingleton&>(Module.Get());
    }

    static FText GetContentBrowserLabelWithIndex(int32 BrowserIdx)
    {
        return FText::Format(NSLOCTEXT("ContentBrowser", "ContentBrowserTabNameWithIndex", "Content Browser {0}"), FText::AsNumber(BrowserIdx + MAX_CONTENT_BROWSERS + 1));
    }
}

FMoreContentBrowserSingleton::FMoreContentBrowserSingleton()
{
    const UMoreContentBrowserSettings* MoreContentBrowserSettings = GetDefault<UMoreContentBrowserSettings>();
    ContentBrowserTabIDs.SetNum(MoreContentBrowserSettings->AdditionalContentBrowserNum);
    if (ContentBrowserTabIDs.Num() >= 1)
    {
        const FSlateIcon ContentBrowserIcon(FAppStyle::Get().GetStyleSetName(), "ContentBrowser.TabIcon");
        const IWorkspaceMenuStructure& MenuStructure = WorkspaceMenu::GetMenuStructure();
        const FName GroupKey = "ContentBrowser";
        const FText GroupDisplayName = LOCTEXT("WorkspaceMenu_ContentBrowserCategory", "Content Browser");
        const FText TooltipText = LOCTEXT("ContentBrowserMenuTooltipText", "Open a Additional Content Browser tab.");
        TSharedRef<FWorkspaceItem> LevelEditorCategory = MenuStructure.GetLevelEditorCategory();
        TSharedPtr<FWorkspaceItem> ContentBrowserGroupPtr;
        for (const TSharedRef<FWorkspaceItem>& Child : LevelEditorCategory->GetChildItems())
        {
            if (Child->GetFName() == GroupKey)
            {
                ContentBrowserGroupPtr = Child;
                break;
            }
        }
        if (!ContentBrowserGroupPtr.IsValid())
        {
            ContentBrowserGroupPtr = LevelEditorCategory->AddGroup(GroupKey, GroupDisplayName, TooltipText, ContentBrowserIcon, true);
        }
        TSharedRef<FWorkspaceItem> ContentBrowserGroup = ContentBrowserGroupPtr.ToSharedRef();
        for (int32 BrowserIdx = 0; BrowserIdx < ContentBrowserTabIDs.Num(); BrowserIdx++)
        {
            const FName TabID = FName(*FString::Printf(TEXT("ContentBrowserTab%d"), BrowserIdx + MAX_CONTENT_BROWSERS + 1));
            ContentBrowserTabIDs[BrowserIdx] = TabID;
            const FText DefaultDisplayName = GetContentBrowserLabelWithIndex(BrowserIdx);
            FTabSpawnerEntry& ContentBrowserTabSpawner = FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabID, FOnSpawnTab::CreateRaw(this, &FMoreContentBrowserSingleton::SpawnContentBrowserTab, BrowserIdx))
                .SetDisplayName(DefaultDisplayName)
                .SetTooltipText(LOCTEXT("ContentBrowserMenuTooltipText", "Open a Content Browser tab."))
                .SetGroup(ContentBrowserGroup)
                .SetIcon(ContentBrowserIcon);
            ContentBrowserTabs.Add(ContentBrowserTabSpawner.AsSpawnerEntry());
        }
        UToolMenu* ContentMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.AddQuickMenu");
        FToolMenuSection& Section = ContentMenu->FindOrAddSection("Content");
        Section.AddSubMenu("MoreContentBrowser", LOCTEXT("ContentBrowserMenu", "More Content Browser"), LOCTEXT("ContentBrowserTooltip", "Actions related to the Content Browser"),
            FNewToolMenuDelegate::CreateRaw(this, &FMoreContentBrowserSingleton::GetContentBrowserSubMenu, ContentBrowserGroup), false,
            FSlateIcon(FAppStyle::Get().GetStyleSetName(), "LevelEditor.OpenContentBrowser"))
            .InsertPosition = FToolMenuInsert("OpenMarketplace", EToolMenuInsertType::After);
    }
}

FMoreContentBrowserSingleton::~FMoreContentBrowserSingleton()
{
}


TSharedRef<SDockTab> FMoreContentBrowserSingleton::SpawnContentBrowserTab(const FSpawnTabArgs& SpawnTabArgs, int32 BrowserIdx)
{
    FContentBrowserSingleton& ContentBrowserSingleton = GetContentBrowserSingleton();
    TAttribute<FText> Label = TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateRaw(this, &FMoreContentBrowserSingleton::GetContentBrowserTabLabel, BrowserIdx));

    TSharedRef<SDockTab> NewTab = SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        .Label(Label)
        .ToolTip(IDocumentation::Get()->CreateToolTip(Label, nullptr, "Shared/ContentBrowser", "Tab"))
        .OnExtendContextMenu_Raw(this, &FMoreContentBrowserSingleton::ExtendContentBrowserTabContextMenu);

    TSharedRef<SWidget> NewBrowser = ContentBrowserSingleton.CreateContentBrowser(SpawnTabArgs.GetTabId().TabType, NewTab, nullptr);

    // Add wrapper for tutorial highlighting
    TSharedRef<SBox> Wrapper =
        SNew(SBox)
        .AddMetaData<FTutorialMetaData>(FTutorialMetaData(TEXT("ContentBrowser"), TEXT("ContentBrowserTab1")))
        [
            NewBrowser
        ];

    NewTab->SetContent(Wrapper);

    return NewTab;
}

FText FMoreContentBrowserSingleton::GetContentBrowserTabLabel(int32 BrowserIdx)
{
    return GetContentBrowserLabelWithIndex(BrowserIdx);
}

void FMoreContentBrowserSingleton::ExtendContentBrowserTabContextMenu(FMenuBuilder& InMenuBuilder)
{
    InMenuBuilder.BeginSection("SummonContentBrowserTabs", LOCTEXT("ContentBrowserTabs", "Content Browser Tabs"));
    for (int32 BrowserIdx = 0; BrowserIdx < ContentBrowserTabIDs.Num(); BrowserIdx++)
    {
        const FName TabID = ContentBrowserTabIDs[BrowserIdx];
        const FText DefaultDisplayName = GetContentBrowserLabelWithIndex(BrowserIdx);

        InMenuBuilder.AddMenuEntry(DefaultDisplayName,
                                   LOCTEXT("ContentBrowserMenuTooltipText", "Open a Content Browser tab."),
                                   FSlateIcon(),
                                   FUIAction(
                                       FExecuteAction::CreateLambda([TabID, this]()
                                           {
                                               // Go through all the content browsers to check if the current one is open
                                               for (int32 BrowserIdx = 0; BrowserIdx < AllContentBrowsers.Num(); ++BrowserIdx)
                                               {
                                                   const TWeakPtr<SContentBrowser>& Browser = AllContentBrowsers[BrowserIdx];

                                                   //if (Browser.IsValid() && Browser.Pin()->GetInstanceName() == TabID)
                                                   //{
                                                   //    FocusContentBrowser(Browser.Pin()); // Focus it if so
                                                   //}
                                               }

                                               // If the tab was not found, try to open it
                                               FGlobalTabmanager::Get()->TryInvokeTab(TabID);
                                           }
                                       ),
                                       FCanExecuteAction(),
                                       FIsActionChecked::CreateLambda([this, TabID]()
                                           {
                                               // Go through all the content browsers to check if the current one is open
                                               for (int32 BrowserIdx = 0; BrowserIdx < AllContentBrowsers.Num(); ++BrowserIdx)
                                               {
                                                   const TWeakPtr<SContentBrowser>& Browser = AllContentBrowsers[BrowserIdx];

                                                   //if (Browser.IsValid() && Browser.Pin()->GetInstanceName() == TabID)
                                                   //{
                                                   //    return true;
                                                   //}
                                               }

                                               return false;
                                           }
                                       )),
                                   NAME_None,
                                   EUserInterfaceActionType::ToggleButton);
    }
    InMenuBuilder.EndSection();
}

void FMoreContentBrowserSingleton::GetContentBrowserSubMenu(UToolMenu* Menu, TSharedRef<FWorkspaceItem> ContentBrowserGroup)
{
    FContentBrowserSingleton& ContentBrowserSingleton = GetContentBrowserSingleton();
    // Register the tab spawners for all content browsers
    const FSlateIcon ContentBrowserIcon(FAppStyle::Get().GetStyleSetName(), "ContentBrowser.TabIcon");
    FToolMenuSection& Section = Menu->AddSection("ContentBrowser");
    Section.AddMenuEntry("FocusContentBrowser",
                         LOCTEXT("FocusContentBrowser_Label", "Focus Content Browser"),
                         LOCTEXT("FocusContentBrowser_Desc", "Focuses the most recently active content browser tab."),
                         FSlateIcon(),
                         FUIAction(FExecuteAction::CreateRaw(&ContentBrowserSingleton, &FContentBrowserSingleton::FocusPrimaryContentBrowser, true), FCanExecuteAction())
    );
    auto AddSpawnerEntryToMenuSection = [](FToolMenuSection& InSection, TSharedPtr<FTabSpawnerEntry> InSpawnerNode, FName InTabID)
    {
        InSection.AddMenuEntry(
            InTabID,
            InSpawnerNode->GetDisplayName().IsEmpty() ? FText::FromName(InTabID) : InSpawnerNode->GetDisplayName(),
            InSpawnerNode->GetTooltipText(),
            FSlateIcon(),
            FGlobalTabmanager::Get()->GetUIActionForTabSpawnerMenuEntry(InSpawnerNode),
            EUserInterfaceActionType::Check
        );
    };
    for (int32 BrowserIdx = 0; BrowserIdx < ContentBrowserTabIDs.Num(); BrowserIdx++)
    {
        const FName TabID = ContentBrowserTabIDs[BrowserIdx];
        AddSpawnerEntryToMenuSection(Section, ContentBrowserTabs[BrowserIdx], TabID);
    }
}

void FMoreContentBrowserSingleton::FocusContentBrowser(const TSharedPtr<SContentBrowser>& BrowserToFocus)
{
    if (BrowserToFocus.IsValid())
    {
        if (BrowserToFocus == ContentBrowserDrawer)
        {
            GEditor->GetEditorSubsystem<UStatusBarSubsystem>()->OpenContentBrowserDrawer();
        }
    }
}

#undef LOCTEXT_NAMESPACE
