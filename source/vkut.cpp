//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off

#include "vkut.h"

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateInstance(
    const VkInstanceCreateInfo&                 createInfo,
    VkInstance&                                 instance) {
    return vkCreateInstance(&createInfo, nullptr, &instance);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyInstance(
    VkInstance                                  instance) {
    vkDestroyInstance(instance, nullptr);
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumeratePhysicalDevices(
    VkInstance                                  instance,
    std::vector<VkPhysicalDevice>&              physicalDevices) {
    // Initialize out parameters.
    physicalDevices.clear();

    // Enumerate all physical devices.
    VkResult status;

    uint32_t count;
    status = vkEnumeratePhysicalDevices(instance, &count, nullptr);

    if (status != VK_SUCCESS && status != VK_INCOMPLETE)
        return status;

    physicalDevices.resize(count);
    status = vkEnumeratePhysicalDevices(instance, &count, &physicalDevices[0]);

    return status;
}

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkQueueFamilyProperties>&       queueFamilyProperties) {
    // Initialize out parameters.
    queueFamilyProperties.clear();

    // Get all queue family properties.
    uint32_t count;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);

    queueFamilyProperties.resize(count);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, &queueFamilyProperties[0]);
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

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceScore(
    VkPhysicalDevice                            physicalDevice,
    uint32_t&                                   score) {
    // Initialize out parameters.
    score = 0;

    // Measure the physical device score.
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);

    switch (properties.deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            score += 200;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            score += 400;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            score += 300;
            break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            score += 100;
            break;
		default:
	        break;
	}
}

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindBestPhysicalDevice(
    VkInstance                                  instance,
    VkPhysicalDevice&                           physicalDevice) {
    // Initialize out paramters.
    physicalDevice = VK_NULL_HANDLE;

    // Find a best physical device.
    VkResult status;

    std::vector<VkPhysicalDevice> physicalDevices;
    status = vuEnumeratePhysicalDevices(instance, physicalDevices);

    if (status != VK_SUCCESS && status != VK_INCOMPLETE)
        return status;

    uint32_t maxScore = 0;
    for (auto i = 0; i != physicalDevices.size(); ++i) {
        uint32_t curScore;
        vuGetPhysicalDeviceScore(physicalDevices[i], curScore);

        if (curScore > maxScore) {
            physicalDevice = physicalDevices[i];
            maxScore = curScore;
        }
    }

    return status;
}

//-----------------------------------------------------------------------------

// clang-format on
