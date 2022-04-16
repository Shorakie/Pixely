project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"%{IncludeDir.spdlog}",
		"%{wks.location}/Pixely/src",
		"%{wks.location}/vendor",
		"%{IncludeDir.glm}"
		-- "%{IncludeDir.entt}"
	}

	links {
		"Pixely"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "PIXELY_DEBUG"
		runtime "Debug"
		symbols "on"
		
		postbuildcommands {
			"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		}

	filter "configurations:Release"
		defines "PIXELY_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PIXELY_DIST"
		runtime "Release"
		optimize "on"
