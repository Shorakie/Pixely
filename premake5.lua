include "Dependencies.lua"

workspace "Pixely"
	architecture "x64"
	startproject "Sandbox"
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	flags {"MultiProcessorCompile"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/imgui.premake5.lua"
	include "vendor/glfw.premake5.lua"
group ""

include "Pixely"
include "Sandbox"
