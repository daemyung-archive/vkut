//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off
#ifndef VKUT_EXTENSION_H_
#define VKUT_EXTENSION_H_

#pragma warning(push)
#pragma warning(disable : 26812)

#include <vulkan/vulkan.h>

#include <vector>

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceScore(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pScore);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindBestPhysicalDevice(
    VkInstance                                  instance,
    VkPhysicalDevice*                           pPhysicalDevice);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindQueueFamilyIndex(
    VkPhysicalDevice                            physicalDevice,
    VkQueueFlags                                queueFlags,
    uint32_t*                                   pQueueFamilyIndex);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindMemoryTypeIndex(
    VkPhysicalDevice                            physicalDevice,
    const VkMemoryRequirements*                 pMemoryRequirements,
    VkMemoryPropertyFlags                       memoryPropertyFlags,
    uint32_t*                                   pMemoryTypeIndex);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCompileShader(
    const std::string*                          pContents,
    const char*                                 pDefines,
    const char*                                 pEntryPoint,
    VkShaderStageFlagBits                       stage,
    std::vector<uint32_t>*                      pCode);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCompileShader(
    const char*                                 pFileName,
    const char*                                 pDefines,
    const char*                                 pEntryPoint,
    VkShaderStageFlagBits                       stage,
    std::vector<uint32_t>*                      pCode);

//-----------------------------------------------------------------------------

#pragma warning(pop)

#endif  // VKUT_EXTENSION_H_

// clang-format on
