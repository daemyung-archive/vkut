//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off

#pragma warning(push)
#pragma warning(disable : 26812)

#include "extension.h"

#include <glslang/SPIRV/GlslangToSpv.h>
#include <fstream>

#include "core.h"

//-----------------------------------------------------------------------------

const TBuiltInResource kDefaultBuiltInResource = {
    /* .MaxLights = */ 32,
    /* .MaxClipPlanes = */ 6,
    /* .MaxTextureUnits = */ 32,
    /* .MaxTextureCoords = */ 32,
    /* .MaxVertexAttribs = */ 64,
    /* .MaxVertexUniformComponents = */ 4096,
    /* .MaxVaryingFloats = */ 64,
    /* .MaxVertexTextureImageUnits = */ 32,
    /* .MaxCombinedTextureImageUnits = */ 80,
    /* .MaxTextureImageUnits = */ 32,
    /* .MaxFragmentUniformComponents = */ 4096,
    /* .MaxDrawBuffers = */ 32,
    /* .MaxVertexUniformVectors = */ 128,
    /* .MaxVaryingVectors = */ 8,
    /* .MaxFragmentUniformVectors = */ 16,
    /* .MaxVertexOutputVectors = */ 16,
    /* .MaxFragmentInputVectors = */ 15,
    /* .MinProgramTexelOffset = */ -8,
    /* .MaxProgramTexelOffset = */ 7,
    /* .MaxClipDistances = */ 8,
    /* .MaxComputeWorkGroupCountX = */ 65535,
    /* .MaxComputeWorkGroupCountY = */ 65535,
    /* .MaxComputeWorkGroupCountZ = */ 65535,
    /* .MaxComputeWorkGroupSizeX = */ 1024,
    /* .MaxComputeWorkGroupSizeY = */ 1024,
    /* .MaxComputeWorkGroupSizeZ = */ 64,
    /* .MaxComputeUniformComponents = */ 1024,
    /* .MaxComputeTextureImageUnits = */ 16,
    /* .MaxComputeImageUniforms = */ 8,
    /* .MaxComputeAtomicCounters = */ 8,
    /* .MaxComputeAtomicCounterBuffers = */ 1,
    /* .MaxVaryingComponents = */ 60,
    /* .MaxVertexOutputComponents = */ 64,
    /* .MaxGeometryInputComponents = */ 64,
    /* .MaxGeometryOutputComponents = */ 128,
    /* .MaxFragmentInputComponents = */ 128,
    /* .MaxImageUnits = */ 8,
    /* .MaxCombinedImageUnitsAndFragmentOutputs = */ 8,
    /* .MaxCombinedShaderOutputResources = */ 8,
    /* .MaxImageSamples = */ 0,
    /* .MaxVertexImageUniforms = */ 0,
    /* .MaxTessControlImageUniforms = */ 0,
    /* .MaxTessEvaluationImageUniforms = */ 0,
    /* .MaxGeometryImageUniforms = */ 0,
    /* .MaxFragmentImageUniforms = */ 8,
    /* .MaxCombinedImageUniforms = */ 8,
    /* .MaxGeometryTextureImageUnits = */ 16,
    /* .MaxGeometryOutputVertices = */ 256,
    /* .MaxGeometryTotalOutputComponents = */ 1024,
    /* .MaxGeometryUniformComponents = */ 1024,
    /* .MaxGeometryVaryingComponents = */ 64,
    /* .MaxTessControlInputComponents = */ 128,
    /* .MaxTessControlOutputComponents = */ 128,
    /* .MaxTessControlTextureImageUnits = */ 16,
    /* .MaxTessControlUniformComponents = */ 1024,
    /* .MaxTessControlTotalOutputComponents = */ 4096,
    /* .MaxTessEvaluationInputComponents = */ 128,
    /* .MaxTessEvaluationOutputComponents = */ 128,
    /* .MaxTessEvaluationTextureImageUnits = */ 16,
    /* .MaxTessEvaluationUniformComponents = */ 1024,
    /* .MaxTessPatchComponents = */ 120,
    /* .MaxPatchVertices = */ 32,
    /* .MaxTessGenLevel = */ 64,
    /* .MaxViewports = */ 16,
    /* .MaxVertexAtomicCounters = */ 0,
    /* .MaxTessControlAtomicCounters = */ 0,
    /* .MaxTessEvaluationAtomicCounters = */ 0,
    /* .MaxGeometryAtomicCounters = */ 0,
    /* .MaxFragmentAtomicCounters = */ 8,
    /* .MaxCombinedAtomicCounters = */ 8,
    /* .MaxAtomicCounterBindings = */ 1,
    /* .MaxVertexAtomicCounterBuffers = */ 0,
    /* .MaxTessControlAtomicCounterBuffers = */ 0,
    /* .MaxTessEvaluationAtomicCounterBuffers = */ 0,
    /* .MaxGeometryAtomicCounterBuffers = */ 0,
    /* .MaxFragmentAtomicCounterBuffers = */ 1,
    /* .MaxCombinedAtomicCounterBuffers = */ 1,
    /* .MaxAtomicCounterBufferSize = */ 16384,
    /* .MaxTransformFeedbackBuffers = */ 4,
    /* .MaxTransformFeedbackInterleavedComponents = */ 64,
    /* .MaxCullDistances = */ 8,
    /* .MaxCombinedClipAndCullDistances = */ 8,
    /* .MaxSamples = */ 4,
    /* .maxMeshOutputVerticesNV = */ 256,
    /* .maxMeshOutputPrimitivesNV = */ 512,
    /* .maxMeshWorkGroupSizeX_NV = */ 32,
    /* .maxMeshWorkGroupSizeY_NV = */ 1,
    /* .maxMeshWorkGroupSizeZ_NV = */ 1,
    /* .maxTaskWorkGroupSizeX_NV = */ 32,
    /* .maxTaskWorkGroupSizeY_NV = */ 1,
    /* .maxTaskWorkGroupSizeZ_NV = */ 1,
    /* .maxMeshViewCountNV = */ 4,
    /* .maxDualSourceDrawBuffersEXT = */ 1,
    /* .limits = */ {
        /* .nonInductiveForLoops = */ 1,
        /* .whileLoops = */ 1,
        /* .doWhileLoops = */ 1,
        /* .generalUniformIndexing = */ 1,
        /* .generalAttributeMatrixVectorIndexing = */ 1,
        /* .generalVaryingIndexing = */ 1,
        /* .generalSamplerIndexing = */ 1,
        /* .generalVariableIndexing = */ 1,
        /* .generalConstantMatrixVectorIndexing = */ 1,
    }
};

//-----------------------------------------------------------------------------

bool IsAnyFlagSet(
    uint32_t                                    value,
    uint32_t                                    test) {
    return (value & test) != 0;
}

//-----------------------------------------------------------------------------

bool IsAllFlagsSet(
    uint32_t                                    value,
    uint32_t                                    test) {
    return (value & test) == test;
}


//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceScore(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pScore) {
    // Initialize out parameters.
    *pScore = 0;

    // Measure the physical device score.
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);

    switch (properties.deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            *pScore += 200;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            *pScore += 400;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            *pScore += 300;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            *pScore += 100;
            break;
		default:
	        break;
	}
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindBestPhysicalDevice(
    VkInstance                                  instance,
    VkPhysicalDevice*                           pPhysicalDevice) {
    // Initialize out paramters.
    *pPhysicalDevice = VK_NULL_HANDLE;

    // Find a best physical device.
    VkResult status;

    std::vector<VkPhysicalDevice> physicalDevices;
    status = vuEnumeratePhysicalDevices(instance, &physicalDevices);

    if (status != VK_SUCCESS && status != VK_INCOMPLETE)
        return status;

    uint32_t maxScore = 0;
    for (auto i = 0; i != physicalDevices.size(); ++i) {
        uint32_t curScore;
        vuGetPhysicalDeviceScore(physicalDevices[i], &curScore);

        if (curScore > maxScore) {
            *pPhysicalDevice = physicalDevices[i];
            maxScore = curScore;
        }
    }

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindQueueFamilyIndex(
    VkPhysicalDevice                            physicalDevice,
    VkQueueFlags                                queueFlags,
    uint32_t*                                   pQueueFamilyIndex) {
    // Initialize out paramters.
    *pQueueFamilyIndex = UINT32_MAX;

    // Find a queue fammily index.
    VkResult status;

    std::vector<VkQueueFamilyProperties> properties;
    vuGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &properties);

    for (auto i = 0; i != properties.size(); ++i) {
        if (!properties[i].queueCount)
            continue;

        if (IsAllFlagsSet(properties[i].queueFlags, queueFlags)) {
            *pQueueFamilyIndex = i;
            break;
        }

        if (IsAnyFlagSet(properties[i].queueFlags, queueFlags))
            *pQueueFamilyIndex = i;
    }

    if (*pQueueFamilyIndex != UINT32_MAX)
        status = VK_SUCCESS;
    else
        status = VK_ERROR_INITIALIZATION_FAILED;

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindMemoryTypeIndex(
    VkPhysicalDevice                            physicalDevice,
    const VkMemoryRequirements*                 pMemoryRequirements,
    VkMemoryPropertyFlags                       memoryPropertyFlags,
    uint32_t*                                   pMemoryTypeIndex) {
    // Initialize out paramters.
    *pMemoryTypeIndex = UINT32_MAX;

    // Find a memory type index.
    VkResult status;

    VkPhysicalDeviceMemoryProperties properties;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &properties);

    for (auto i = 0; i != properties.memoryTypeCount; ++i) {
        if (!IsAllFlagsSet(pMemoryRequirements->memoryTypeBits, 1 << i))
            continue;

        auto& memory_type = properties.memoryTypes[i];
        if (!IsAllFlagsSet(memory_type.propertyFlags, memoryPropertyFlags))
            continue;

        *pMemoryTypeIndex = i;
    }

    if (*pMemoryTypeIndex != UINT32_MAX)
        status = VK_SUCCESS;
    else
        status = VK_ERROR_INITIALIZATION_FAILED;

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCompileShader(
    const std::string*                          pContents,
    const char*                                 pDefines,
    const char*                                 pEntryPoint,
    VkShaderStageFlagBits                       stage,
    std::vector<uint32_t>*                      pCode) {
    // Initialize out paramters.
    pCode->clear();

    // Find EShLanguage.
    EShLanguage language;

    switch (stage) {
        case VK_SHADER_STAGE_VERTEX_BIT:
            language = EShLangVertex;
            break;
        case VK_SHADER_STAGE_FRAGMENT_BIT:
            language = EShLangFragment;
            break;
        default:
            return VK_ERROR_DEVICE_LOST;
    }

    // Initialize Glslang.
    glslang::InitializeProcess();

    // Create TShader.
    glslang::TShader shader(language);

    // Set up the environment.
    shader.setEnvInput(glslang::EShSourceGlsl, language, glslang::EShClientVulkan, 100);
    shader.setEnvClient(glslang::EShClientVulkan, glslang::EShTargetVulkan_1_1);
    shader.setEnvTarget(glslang::EShTargetSpv, glslang::EShTargetSpv_1_0);

    // Set up the code.
    std::vector<const char*> strings { pContents->c_str() };
    shader.setStrings(strings.data(), strings.size());

    // Parse TShader.
    if (!shader.parse(&kDefaultBuiltInResource, 450, false, EShMsgDefault)) {
        assert(false);
    }

    // Create TProgram.
    glslang::TProgram program;

    // Add TShaders.
    program.addShader(&shader);

    // Link TProgram.
    if (!program.link(EShMsgDefault)) {
        assert(false);
    }

    // Map IO TProgram.
    if (!program.mapIO()) {
        assert(false);
    }

    // Generate SPIRV.
    GlslangToSpv(*program.getIntermediate(language), *pCode);

    // Finalize Glslang.
    glslang::FinalizeProcess();

    return VK_SUCCESS;

}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCompileShader(
    const char*                                 pFileName,
    const char*                                 pDefines,
    const char*                                 pEntryPoint,
    VkShaderStageFlagBits                       stage,
    std::vector<uint32_t>*                      pCode) {
    // Read a file.
    std::ifstream fin(pFileName, std::ios::binary);
    std::string data { std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>() };

    if (!fin.is_open() || data.empty())
        return VK_ERROR_DEVICE_LOST;

    return vuCompileShader(&data, pDefines, pEntryPoint, stage, pCode);
}

//-----------------------------------------------------------------------------

#pragma warning(pop)

// clang-format on
