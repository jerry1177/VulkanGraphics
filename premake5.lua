workspace "VulkanGraphics"
	architecture "x64"
	startproject "VulkanProgram"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "VulkanProgram/vendor/GLFW/include"
IncludeDir["Glad"] = "VulkanProgram/vendor/Glad/include"
IncludeDir["Vulkan"] = "C:/VulkanSDK/1.2.170.0/Include"
IncludeDir["glm"] = "VulkanProgram/vendor/glm"
IncludeDir["stb_image"] = "VulkanProgram/vendor/stb_image"

include "VulkanProgram/vendor/GLFW"

project "VulkanProgram"
	location "VulkanProgram"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "VulkanProgram/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Vulkan}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	libdirs {
		"C:/VulkanSDK/1.2.170.0/Lib"

	}

	links {
		"GLFW",
		"vulkan-1.lib"
	}
	


	filter "system:windows"

		systemversion "latest"

		defines
		{
			"_GLFW_WIN32",
			"_WIND32",
			"_WIND64",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "G_DEBUG"
		runtime "Debug"
		symbols "on"
		

	filter "configurations:Release"
		defines "G_RELEASE"
		runtime "Release"
		optimize "on"
		symbols "on"

	filter "configurations:Dist"
		defines "G_DIST"
		runtime "Release"
		optimize "on"
		symbols "on"

	filter "system:macosx"
    defines {
      "G_MAC",
      "__APPLE__"
    }

    links {
      "OpenGL.framework",
      "Cocoa.framework",
      "IOKit.framework",
      "CoreFoundation.framework"
    }


