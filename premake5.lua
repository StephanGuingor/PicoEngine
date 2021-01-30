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

project "Psico"
    location "Psico"
    kind "SharedLib"
    language "C++"

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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PS_PLATFORM_WINDOW",
            "PS_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PS_RELEASE"
        optimize  "On"

    filter "configurations:Release"
        defines "PS_DIST"
        optimize  "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "PS_PLATFORM_WINDOW",
    }


    filter "configurations:Debug"
        defines "PS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PS_RELEASE"
        optimize  "On"

    filter "configurations:Release"
        defines "PS_DIST"
        optimize  "On"
