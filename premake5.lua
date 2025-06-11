workspace "OpenGLStudy"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    startproject "OpenGLStudy"

    local vcpkgTriplet = os.getenv("VCPKG_DEFAULT_TRIPLET") or "x64-windows"
    local vcpkgIncludeDirs = {}
    local vcpkgLibDirs = {}
    if vcpkgRoot then
        os.setenv("VCPKG_ROOT", vcpkgRoot)
        os.setenv("VCPKG_DEFAULT_TRIPLET", vcpkgTriplet)
        os.setenv("VCPKG_FEATURE_FLAGS", "manifests")

        -- When building with a manifest, libraries live under vcpkg_installed
        local manifestRoot = path.getabsolute("vcpkg_installed")
        if os.isdir(manifestRoot) then
            local installDir = path.join(manifestRoot, vcpkgTriplet)
            if os.isdir(path.join(installDir, vcpkgTriplet)) then
                installDir = path.join(installDir, vcpkgTriplet)
            end
            if os.isdir(installDir) then
                table.insert(vcpkgIncludeDirs, path.join(installDir, "include"))
                table.insert(vcpkgLibDirs, path.join(installDir, "lib"))
                table.insert(vcpkgLibDirs, path.join(installDir, "debug", "lib"))
            end
        end

        local installedDir = path.join(vcpkgRoot, "installed", vcpkgTriplet)
        if os.isdir(installedDir) then
            table.insert(vcpkgIncludeDirs, path.join(installedDir, "include"))
            table.insert(vcpkgLibDirs, path.join(installedDir, "lib"))
            table.insert(vcpkgLibDirs, path.join(installedDir, "debug", "lib"))
        else
            for _, pkg in ipairs(os.matchdirs(path.join(vcpkgRoot, "packages/*_" .. vcpkgTriplet))) do
                local inc = path.join(pkg, "include")
                if os.isdir(inc) then table.insert(vcpkgIncludeDirs, inc) end
                local lib = path.join(pkg, "lib")
                if os.isdir(lib) then table.insert(vcpkgLibDirs, lib) end
                local libDbg = path.join(pkg, "debug", "lib")
                if os.isdir(libDbg) then table.insert(vcpkgLibDirs, libDbg) end
            end
        end
    end

project "OpenGLStudy"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    files {
        "Program/**.h",
        "Program/**.cpp",
        "Core/**.h",
        "Core/**.cpp",
        "ThirdParty/glad/src/glad.c"
    }

    includedirs {
        ".",
        "Core",
        "Program",
        "ThirdParty/glfw/include",
        "ThirdParty/glad/include",
        "ThirdParty/glm",
        "ThirdParty/stb",
        "ThirdParty/tinyexr",
        "ThirdParty/tinyexr/deps/miniz",
        "ThirdParty/boost_patch",
        "ThirdParty/entt/include"
    }

    if #vcpkgIncludeDirs > 0 then
        includedirs(vcpkgIncludeDirs)
    end

    if #vcpkgLibDirs > 0 then
        libdirs(vcpkgLibDirs)
    end

    defines {
        "BOOST_THREAD_PROVIDES_FUTURE",
        "BOOST_THREAD_VERSION=5",
        "TINYEXR_USE_MINIZ=0"
    }

    links {
        "opengl32",
        "assimp",
        "glfw3",
        "BulletDynamics",
        "BulletCollision",
        "LinearMath",
        "zlib",
        "boost_thread",
        "boost_system"
    }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter "system:windows"
        systemversion "latest"
        toolset "v143"
        buildoptions { "/EHsc" }
        postbuildcommands {
            "{MKDIR} %{cfg.targetdir}/Assets",
            "{COPYDIR} %{wks.location}/Assets %{cfg.targetdir}/Assets"
        }