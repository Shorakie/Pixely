project "Pixely"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pixelypch.h"
	pchsource "src/pixelypch.cpp"

	files {
		"src/**.hpp",
		"src/**.cpp",
		"src/**.h",
		"src/**.c"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"PIXELY_LIB",
		"GLFW_INCLUDE_NONE"
	}

	includedirs {
		"src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.Tracy}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.VulkanSDK}"
		-- "%{IncludeDir.Glad}",
		-- "%{IncludeDir.stb_image}",
		-- "%{IncludeDir.entt}",
		-- "%{IncludeDir.yaml_cpp}",
		-- "%{IncludeDir.ImGuizmo}",
	}

	links {
		"GLFW",
		"ImGui"
		-- "Glad",
		-- "yaml-cpp",
		-- "opengl32.lib"
	}

	filter "files:%{wks.location}/vendor/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines {}

	filter "configurations:Debug"
		defines "PIXELY_DEBUG"
		runtime "Debug"
		symbols "on"

		links {
			-- "%{Library.ShaderC_Debug}",
			-- "%{Library.SPIRV_Cross_Debug}",
			-- "%{Library.SPIRV_Cross_GLSL_Debug}"
		}

	filter "configurations:Release"
		defines "PIXELY_RELEASE"
		runtime "Release"
		optimize "on"

		links {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		}

	filter "configurations:Dist"
		defines "PIXELY_DIST"
		runtime "Release"
		optimize "on"

		links {
			-- "%{Library.ShaderC_Release}",
			-- "%{Library.SPIRV_Cross_Release}",
			-- "%{Library.SPIRV_Cross_GLSL_Release}"
		}
