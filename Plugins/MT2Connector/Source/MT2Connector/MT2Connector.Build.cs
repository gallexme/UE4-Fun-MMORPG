// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
using System.IO;
namespace UnrealBuildTool.Rules
{
    public class MT2Connector : ModuleRules
    {
        protected string ModulePath
        {
            get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
        }
        protected string LibPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "Private", "Libraries")); }
        }
        public MT2Connector(TargetInfo Target)
        {

            PublicIncludePaths.AddRange(
                new string[] {
                    ModulePath+"/Public",
                    ModulePath+"/Classes",
					// ... add public include paths required here ...
				}
                );

            PrivateIncludePaths.AddRange(
                new string[] {
                    ModulePath+"/Private",
                    "D:/Development/Libraries/cryptopp/include",
                    "D:/Development/Libraries/boost_1_57_0",
                    "D:/Development/M2CL/M2CL-C/cipher"
                    // ... add other private include paths required here ...
                }
                );

            PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

            PrivateDependencyModuleNames.AddRange(
                new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
                );

            DynamicallyLoadedModuleNames.AddRange(
                new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
                );
            System.Console.Write(ModulePath);
            PublicAdditionalLibraries.Add(LibPath + "/Cipher.lib");
            PublicAdditionalLibraries.Add("D:/Development/Libraries/boost_1_57_0/stage/lib/libboost_system-vc120-mt-1_57.lib");
            PublicAdditionalLibraries.Add("D:/Development/Libraries/boost_1_57_0/stage/lib/libboost_regex-vc120-mt-1_57.lib");
            PublicAdditionalLibraries.Add("D:/Development/Libraries/boost_1_57_0/stage/lib/libboost_date_time-vc120-mt-1_57.lib");
            PublicAdditionalLibraries.Add("D:/Development/Libraries/boost_1_57_0/stage/lib/libboost_thread-vc120-mt-1_57.lib");
            PublicAdditionalLibraries.Add("D:/Development/Libraries/boost_1_57_0/stage/lib/libboost_chrono-vc120-mt-1_57.lib");
            //  PublicAdditionalLibraries.Add();


        }
    }
}