workspace "Aku"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Aku"
	location "Aku"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "akpch.h"
	pchsource "Aku/src/akpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines
		{
			"AKU_PLATFORM_WINDOWS",
			"AKU_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestGame")
		}

	filter "configurations:Debug"
		defines "AKU_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AKU_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AKU_DIST"
		symbols "On"

project "TestGame"
	location "TestGame"
	kind "ConsoleApp"

	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Aku/vendor/spdlog/include",
		"Aku/src"
	}

	links
	{
		"Aku"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines
		{
			"AKU_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AKU_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AKU_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "AKU_DIST"
		symbols "On"