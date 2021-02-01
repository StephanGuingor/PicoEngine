workspace "Psico"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root (sln)
IncludeDir  = {}
IncludeDir["GLFW"] = "Psico/vendor/GLFW/include"
IncludeDir["GLAD"] = "Psico/vendor/GLAD/include"
IncludeDir["ImGui"] = "Psico/vendor/imgui"

-- Include premake
group "Dependencies"
    include "Psico/vendor/GLFW"
    include "Psico/vendor/GLAD"
    include "Psico/vendor/imgui"
group ""

project "Psico"
    location "Psico"
    kind "SharedLib"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pspch.h"
    pchsource "Psico/src/pspch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PS_PLATFORM_WINDOW",
            "PS_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines 
        {
            "PS_DEBUG",
            "PS_ENABLE_ASSERTS"
        }
        symbols "On"
        runtime "Debug"
        
    filter "configurations:Release"
        defines "PS_RELEASE"
        optimize  "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "PS_DIST"
        optimize  "On"
        runtime "Release"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "Psico/vendor/spdlog/include",
        "Psico/src"
    }

    links
    {
        "Psico"
    }

    filter "system:windows"
    cppdialect "C++17"
    systemversion "latest"

    defines
    {
        "PS_PLATFORM_WINDOW",
    }


    filter "configurations:Debug"
        defines "PS_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "PS_RELEASE"
        optimize  "On"
        runtime "Release"


    filter "configurations:Release"
        defines "PS_DIST"
        optimize  "On"
        runtime "Release"

