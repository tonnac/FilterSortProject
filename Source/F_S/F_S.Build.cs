// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class F_S : ModuleRules
{
	private string ProjectDirectory
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../"));
		}
	}
	
	private string PluginDir
    {
    	get
    	{
    		return ProjectDirectory + "/Plugins/";
    	}
    }

	public F_S(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"UMG"
		});
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"FilterSort"
		});
		PublicIncludePathModuleNames.AddRange(new string[]
		{
			"FilterSort"
		});
		
		PublicIncludePaths.AddRange(new string[]
		{
			"F_S/FilterSort", 
			"F_S/FilterSort/AObjectFilter"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
