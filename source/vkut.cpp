//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off

#include "vkut.h"

#include <glslang/SPIRV/GlslangToSpv.h>
#include <fstream>

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

VKAPI_ATTR VkResult VKAPI_CALL vuCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    VkInstance*                                 pInstance) {
    return vkCreateInstance(pCreateInfo, nullptr, pInstance);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyInstance(
    VkInstance                                  instance) {
    vkDestroyInstance(instance, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumeratePhysicalDevices(
    VkInstance                                  instance,
    std::vector<VkPhysicalDevice>*              pPhysicalDevices) {
    // Initialize out parameters.
    pPhysicalDevices->clear();

    // Enumerate all physical devices.
    VkResult status;

    uint32_t count;
    status = vkEnumeratePhysicalDevices(instance, &count, nullptr);

    if (status != VK_SUCCESS && status != VK_INCOMPLETE)
        return status;

    pPhysicalDevices->resize(count);
    status = vkEnumeratePhysicalDevices(instance, &count, pPhysicalDevices->data());

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkQueueFamilyProperties>*       pQueueFamilyProperties) {
    // Initialize out parameters.
    pQueueFamilyProperties->clear();

    // Get all queue family properties.
    uint32_t count;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);

    pQueueFamilyProperties->resize(count);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, pQueueFamilyProperties->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    VkDevice*                                   pDevice) {
    return vkCreateDevice(physicalDevice, pCreateInfo, nullptr, pDevice);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDevice(
    VkDevice                                    device) {
    vkDestroyDevice(device, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
    std::vector<VkExtensionProperties>*         pProperties) {
    return vuEnumerateInstanceExtensionProperties(nullptr, pProperties);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
    const char*                                 pLayerName,
    std::vector<VkExtensionProperties>*         pProperties) {
    // Initialize out paramters.
    pProperties->clear();

    // Enumerate all instance extension properties.
    VkResult status;

    uint32_t count;
    status = vkEnumerateInstanceExtensionProperties(pLayerName, &count, nullptr);

    if (status != VK_SUCCESS)
        return status;

    pProperties->resize(count);
    status = vkEnumerateInstanceExtensionProperties(pLayerName, &count, pProperties->data());

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkExtensionProperties>*         pProperties) {
    return vuEnumerateDeviceExtensionProperties(physicalDevice, nullptr, pProperties);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    const char*                                 pLayerName,
    std::vector<VkExtensionProperties>*         pProperties) {
    // Initialize out paramters.
    pProperties->clear();

    // Enumerate all device extension properties.
    VkResult status;

    uint32_t count;
    status = vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, &count, nullptr);

    if (status != VK_SUCCESS)
        return status;

    pProperties->resize(count);
    status = vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, &count, pProperties->data());

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceLayerProperties(
    std::vector<VkLayerProperties>*             pProperties) {
    // Initialize out paramters.
    pProperties->clear();

    // Enumerate all instance layer properties.
    VkResult status;

    uint32_t count;
    status = vkEnumerateInstanceLayerProperties(&count, nullptr);

    if (status != VK_SUCCESS)
        return status;

    pProperties->resize(count);
    status = vkEnumerateInstanceLayerProperties(&count, pProperties->data());

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const VkSubmitInfo*                         pSubmit,
    VkFence                                     fence) {
    return vkQueueSubmit(queue, 1, pSubmit, fence);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const std::vector<VkSubmitInfo>*            pSubmits,
    VkFence                                     fence) {
    return vkQueueSubmit(queue, static_cast<uint32_t>(pSubmits->size()), pSubmits->data(), fence);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    VkDeviceMemory*                             pMemory) {
    return vkAllocateMemory(device, pAllocateInfo, nullptr, pMemory);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory) {
    vkFreeMemory(device, memory, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    void**                                      ppData) {
    return vkMapMemory(device, memory, 0, VK_WHOLE_SIZE, 0, ppData);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory) {
    return vkBindBufferMemory(device, buffer, memory, 0);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory) {
    return vkBindImageMemory(device, image, memory, 0);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    VkFence*                                    pFence) {
    return vkCreateFence(device, pCreateInfo, nullptr, pFence);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence) {
    vkDestroyFence(device, fence, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    VkSemaphore*                                pSemaphore) {
    return vkCreateSemaphore(device, pCreateInfo, nullptr, pSemaphore);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore) {
    vkDestroySemaphore(device, semaphore, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    VkEvent*                                    pEvent) {
    return vkCreateEvent(device, pCreateInfo, nullptr, pEvent);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event) {
    return vkDestroyEvent(device, event, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    VkQueryPool*                                pQueryPool) {
    return vkCreateQueryPool(device, pCreateInfo, nullptr, pQueryPool);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool) {
    vkDestroyQueryPool(device, queryPool, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    VkBuffer*                                   pBuffer) {
    return vkCreateBuffer(device, pCreateInfo, nullptr, pBuffer);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer) {
    vkDestroyBuffer(device, buffer, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    VkBufferView*                               pView) {
    return vkCreateBufferView(device, pCreateInfo, nullptr, pView);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView) {
    vkDestroyBufferView(device, bufferView, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    VkImage*                                    pImage) {
    return vkCreateImage(device, pCreateInfo, nullptr, pImage);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyImage(
    VkDevice                                    device,
    VkImage                                     image) {
    vkDestroyImage(device, image, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    VkImageView*                                pView) {
    return vkCreateImageView(device, pCreateInfo, nullptr, pView);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView) {
    vkDestroyImageView(device, imageView, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModule*                             pShaderModule) {
    return vkCreateShaderModule(device, pCreateInfo, nullptr, pShaderModule);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule) {
    vkDestroyShaderModule(device, shaderModule, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    VkPipelineCache*                            pPipelineCache) {
    return vkCreatePipelineCache(device, pCreateInfo, nullptr, pPipelineCache);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache) {
    vkDestroyPipelineCache(device, pipelineCache, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    VkPipeline*                                 pPipelines) {
    return vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, nullptr, pPipelines);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    VkPipeline*                                 pPipelines) {
    return vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, nullptr, pPipelines);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline) {
    vkDestroyPipeline(device, pipeline, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    VkPipelineLayout*                           pPipelineLayout) {
    return vkCreatePipelineLayout(device, pCreateInfo, nullptr, pPipelineLayout);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout) {
    vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    VkSampler*                                  pSampler) {
    return vkCreateSampler(device, pCreateInfo, nullptr, pSampler);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler) {
    vkDestroySampler(device, sampler, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayout*                      pSetLayout) {
    return vkCreateDescriptorSetLayout(device, pCreateInfo, nullptr, pSetLayout);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout) {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    VkDescriptorPool*                           pDescriptorPool) {
    return vkCreateDescriptorPool(device, pCreateInfo, nullptr, pDescriptorPool);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool) {
    vkDestroyDescriptorPool(device, descriptorPool, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    VkFramebuffer*                              pFramebuffer) {
    return vkCreateFramebuffer(device, pCreateInfo, nullptr, pFramebuffer);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer) {
    vkDestroyFramebuffer(device, framebuffer, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    VkRenderPass*                               pRenderPass) {
    return vkCreateRenderPass(device, pCreateInfo, nullptr, pRenderPass);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass) {
    vkDestroyRenderPass(device, renderPass, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    VkCommandPool*                              pCommandPool) {
    return vkCreateCommandPool(device, pCreateInfo, nullptr, pCommandPool);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool) {
    vkDestroyCommandPool(device, commandPool, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffer(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkCommandBuffer*                      pCommandBuffer) {
    vkFreeCommandBuffers(device, commandPool, 1, pCommandBuffer);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const std::vector<VkCommandBuffer>*         pCommandBuffers) {
    vkFreeCommandBuffers(device, commandPool, static_cast<uint32_t>(pCommandBuffers->size()), pCommandBuffers->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const VkBufferCopy*                         pRegion) {
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, pRegion);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferCopy>*            pRegions) {
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageCopy*                          pRegion) {
    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, 1, pRegion);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkImageCopy>*             pRegions) {
    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageBlit*                          pRegion,
    VkFilter                                    filter) {
    vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, 1, pRegion, filter);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkImageBlit>*             pRegions,
    VkFilter                                    filter) {
    vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(pRegions->size()), pRegions->data(), filter);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkBufferImageCopy*                    pRegion) {
    vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, 1, pRegion);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkBufferImageCopy>*       pRegions) {
    vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const VkBufferImageCopy*                    pRegion) {
    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, 1, pRegion);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferImageCopy>*       pRegions) {
    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const VkImageMemoryBarrier*                 pImageMemoryBarrier) {
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, 0, nullptr, 0, nullptr, 1, pImageMemoryBarrier);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const std::vector<VkImageMemoryBarrier>*    pImageMemoryBarriers) {
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, 0, nullptr, 0, nullptr, static_cast<uint32_t>(pImageMemoryBarriers->size()), pImageMemoryBarriers->data());
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

// clang-format on
