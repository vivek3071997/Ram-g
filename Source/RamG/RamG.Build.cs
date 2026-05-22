using UnrealBuildTool;

public class RamG : ModuleRules
{
	public RamG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" 
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
