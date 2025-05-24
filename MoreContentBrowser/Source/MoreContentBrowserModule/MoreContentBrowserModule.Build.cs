// copyright 2024 kiruru002.

using UnrealBuildTool;

public class MoreContentBrowserModule : ModuleRules
{
	public MoreContentBrowserModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
				"Editor/ContentBrowser/Private",
			}
		);
		
		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
				"MainFrame",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AssetDefinition",
				"AppFramework",
				"Core",
				"CoreUObject",
				"ApplicationCore",
				"InputCore",
				"EditorConfig",
				"Engine",
				"Slate",
				"SlateCore",
				"EditorStyle",
				"AssetTools",
				"ContentBrowserData",
				"SourceControl",
				"SourceControlWindows",
				"WorkspaceMenuStructure",
				"EditorFramework",
				"UnrealEd",
				"EditorWidgets",
				"Projects",
				"AddContentDialog",
				"DesktopPlatform",
				"AssetRegistry",
				"AssetTagsEditor",
				"ToolMenus",
				"StatusBar",
				"ToolWidgets",
				"TelemetryUtils",
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				"PropertyEditor",
				"PackagesDialog",
				"CollectionManager",
				"GameProjectGeneration",
				"MainFrame",
			}
		);

		PublicIncludePathModuleNames.AddRange(
			new string[]
			{
				"AssetTools",
				"CollectionManager",
				"ContentBrowserData",
			}
		);
	}
}