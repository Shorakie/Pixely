VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
-- IncludeDir["stb_image"] = "%{wks.location}/Pixely/vendor/stb_image"
-- IncludeDir["yaml_cpp"] = "%{wks.location}/Pixely/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/vendor/glfw/include"
-- IncludeDir["Glad"] = "%{wks.location}/Pixely/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/vendor/glm"
IncludeDir["spdlog"] = "%{wks.location}/vendor/spdlog/include"
IncludeDir["Tracy"] = "%{wks.location}/vendor/tracy"
-- IncludeDir["entt"] = "%{wks.location}/Pixely/vendor/entt/include"
-- IncludeDir["shaderc"] = "%{wks.location}/Pixely/vendor/shaderc/include"
-- IncludeDir["SPIRV_Cross"] = "%{wks.location}/Pixely/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{VULKAN_SDK}/Bin"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"
