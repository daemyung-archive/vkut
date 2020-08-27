//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off
#ifndef VKUT_VKUT_H_
#define VKUT_VKUT_H_

#pragma warning(disable : 26812)

#include <vulkan/vulkan.h>

#include <vector>

//-----------------------------------------------------------------------------

struct VuApplicationInfo : VkApplicationInfo {
    VuApplicationInfo() {
        sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        pNext = nullptr;
        pApplicationName = nullptr;
        applicationVersion = VK_MAKE_VERSION(0, 0, 0);
        pEngineName = nullptr;
        engineVersion = VK_MAKE_VERSION(0, 0, 0);
        apiVersion = VK_API_VERSION_1_0;
    }

    void SetApplicationInfo(const char* pName, uint8_t major, uint32_t minor, uint32_t patch) {
        pApplicationName = pName;
        applicationVersion = VK_MAKE_VERSION(major, minor, patch);
    }

    void SetEngineInfo(const char* pName, uint8_t major, uint32_t minor, uint32_t patch) {
        pEngineName = pName;
        engineVersion = VK_MAKE_VERSION(major, minor, patch);
    }
};

//-----------------------------------------------------------------------------

struct VuInstanceCreateInfo : VkInstanceCreateInfo {
    VuInstanceCreateInfo() {
        sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        pApplicationInfo = nullptr;
        enabledLayerCount = 0;
        ppEnabledLayerNames = nullptr;
        enabledExtensionCount = 0;
        ppEnabledExtensionNames = nullptr;
    }

    void SetEnabledLayerName(const char** ppName) {
        enabledLayerCount = 1;
        ppEnabledLayerNames = ppName;
    }

    void SetEnabledLayerNames(const std::vector<const char*>* pNames) {
        enabledLayerCount = static_cast<uint32_t>(pNames->size());
        ppEnabledLayerNames = pNames->data();
    }

    void SetEnabledExtensionName(const char** ppName) {
        enabledExtensionCount = 1;
        ppEnabledExtensionNames = ppName;
    }

    void SetEnabledExtensionNames(const std::vector<const char*>* pNames) {
        enabledExtensionCount = static_cast<uint32_t>(pNames->size());
        ppEnabledExtensionNames = pNames->data();
    }
};

//-----------------------------------------------------------------------------

struct VuExtent3D : VkExtent3D {
    VuExtent3D() {
        width = 0;
        height = 0;
        depth = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuDeviceQueueCreateInfo : VkDeviceQueueCreateInfo {
    VuDeviceQueueCreateInfo() {
        sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queueFamilyIndex = 0;
        queueCount = 0;
        pQueuePriorities = nullptr;
    }

    void SetQueueInfo(uint32_t count, const float* pPriorities) {
        queueCount = count;
        pQueuePriorities = pPriorities;
    }
};

//-----------------------------------------------------------------------------

struct VuDeviceCreateInfo : VkDeviceCreateInfo {
    VuDeviceCreateInfo() {
        sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queueCreateInfoCount = 0;
        pQueueCreateInfos = nullptr;
        enabledLayerCount = 0;
        ppEnabledLayerNames = nullptr;
        enabledExtensionCount = 0;
        ppEnabledExtensionNames = nullptr;
        pEnabledFeatures = nullptr;
    }

    void SetQueueCreateInfo(const VkDeviceQueueCreateInfo* pCreateInfo) {
        queueCreateInfoCount = 1;
        pQueueCreateInfos = pCreateInfo;
    }

    void SetQueueCreateInfos(const std::vector<VkDeviceQueueCreateInfo>* pCreateInfos) {
        queueCreateInfoCount = static_cast<uint32_t>(pCreateInfos->size());
        pQueueCreateInfos = pCreateInfos->data();
    }

    void SetEnabledExtensionName(const char** ppName) {
        enabledExtensionCount = 1;
        ppEnabledExtensionNames = ppName;
    }

    void SetEnabledExtensionNames(const std::vector<const char*>* pNames) {
        enabledExtensionCount = static_cast<uint32_t>(pNames->size());
        ppEnabledExtensionNames = pNames->data();
    }
};

//-----------------------------------------------------------------------------

struct VuSubmitInfo : VkSubmitInfo {
    VuSubmitInfo() {
        sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        pNext = nullptr;
        waitSemaphoreCount = 0;
        pWaitSemaphores = nullptr;
        pWaitDstStageMask = nullptr;
        commandBufferCount = 0;
        pCommandBuffers = nullptr;
        signalSemaphoreCount = 0;
        pSignalSemaphores = nullptr;
    }

    void SetCommandBuffer(const VkCommandBuffer* pCommandBuffer) {
        commandBufferCount = 1;
        pCommandBuffers = pCommandBuffer;
    }
};

//-----------------------------------------------------------------------------

struct VuMemoryAllocateInfo : VkMemoryAllocateInfo {
    VuMemoryAllocateInfo() {
        sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        pNext = nullptr;
        allocationSize = 0;
        memoryTypeIndex = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuMappedMemoryRange : VkMappedMemoryRange {
    VuMappedMemoryRange() {
        sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
        pNext = nullptr;
        memory = VK_NULL_HANDLE;
        offset = 0;
        size = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuBindSparseInfo : VkBindSparseInfo {
    VuBindSparseInfo() {
        sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
        pNext = nullptr;
        waitSemaphoreCount = 0;
        pWaitSemaphores = nullptr;
        bufferBindCount = 0;
        pBufferBinds = nullptr;
        imageOpaqueBindCount = 0;
        pImageOpaqueBinds = nullptr;
        imageBindCount = 0;
        pImageBinds = nullptr;
        signalSemaphoreCount = 0;
        pSignalSemaphores = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VuFenceCreateInfo : VkFenceCreateInfo {
    VuFenceCreateInfo() {
        sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuSemaphoreCreateInfo : VkSemaphoreCreateInfo {
    VuSemaphoreCreateInfo() {
        sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuEventCreateInfo : VkEventCreateInfo {
    VuEventCreateInfo() {
        sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuQueryPoolCreateInfo : VkQueryPoolCreateInfo {
    VuQueryPoolCreateInfo() {
        sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queryType = VK_QUERY_TYPE_OCCLUSION;
        queryCount = 0;
        pipelineStatistics = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuBufferCreateInfo : VkBufferCreateInfo {
    VuBufferCreateInfo() {
        sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        size = 0;
        usage = 0;
        sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        queueFamilyIndexCount = 0;
        pQueueFamilyIndices = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VuBufferViewCreateInfo : VkBufferViewCreateInfo {
    VuBufferViewCreateInfo() {
        sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        buffer = VK_NULL_HANDLE;
        format = VK_FORMAT_UNDEFINED;
        offset = 0;
        range = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuImageCreateInfo : VkImageCreateInfo {
    VuImageCreateInfo() {
        sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        imageType = VK_IMAGE_TYPE_1D;
        format = VK_FORMAT_UNDEFINED;
        extent = VuExtent3D();
        mipLevels = 1;
        arrayLayers = 1;
        samples = VK_SAMPLE_COUNT_1_BIT;
        usage = 0;
        sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        queueFamilyIndexCount = 0;
        pQueueFamilyIndices = nullptr;
        initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    }
};

//-----------------------------------------------------------------------------

struct VuComponentMapping : VkComponentMapping {
    VuComponentMapping() {
        r = VK_COMPONENT_SWIZZLE_IDENTITY;
        g = VK_COMPONENT_SWIZZLE_IDENTITY;
        b = VK_COMPONENT_SWIZZLE_IDENTITY;
        a = VK_COMPONENT_SWIZZLE_IDENTITY;
    }
};

//-----------------------------------------------------------------------------

struct VuImageSubresourceRange : VkImageSubresourceRange {
    VuImageSubresourceRange() {
        aspectMask = 0;
        baseMipLevel = 0;
        levelCount = 0;
        baseArrayLayer = 0;
        layerCount = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuImageViewCreateInfo : VkImageViewCreateInfo {
    VuImageViewCreateInfo() {
        sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        image = VK_NULL_HANDLE;
        viewType = VK_IMAGE_VIEW_TYPE_1D;
        format = VK_FORMAT_UNDEFINED;
        components = VuComponentMapping();
        subresourceRange = VuImageSubresourceRange();
    }
};

//-----------------------------------------------------------------------------

struct VuCommandPoolCreateInfo : VkCommandPoolCreateInfo {
    VuCommandPoolCreateInfo() {
        sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queueFamilyIndex = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuCommandBufferAllocateInfo : VkCommandBufferAllocateInfo {
    VuCommandBufferAllocateInfo() {
        sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        pNext = nullptr;
        commandPool = VK_NULL_HANDLE;
        level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        commandBufferCount = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuCommandBufferBeginInfo : VkCommandBufferBeginInfo {
    VuCommandBufferBeginInfo() {
        sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        pNext = nullptr;
        flags = 0;
        pInheritanceInfo = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VuImageMemoryBarrier : VkImageMemoryBarrier {
    VuImageMemoryBarrier() {
        sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        pNext = nullptr;
        srcAccessMask = 0;
        dstAccessMask = 0;
        oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        newLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        srcQueueFamilyIndex = 0;
        dstQueueFamilyIndex = 0;
        image = VK_NULL_HANDLE;
        subresourceRange = VuImageSubresourceRange();
    }

    void SetQueueFamilyIndex(uint32_t queueFamilyIndex) {
        srcQueueFamilyIndex = queueFamilyIndex;
        dstQueueFamilyIndex = queueFamilyIndex;
    }
};

//-----------------------------------------------------------------------------

struct VuSamplerCreateInfo : VkSamplerCreateInfo {
    VuSamplerCreateInfo() {
        sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        magFilter = VK_FILTER_NEAREST;
        minFilter = VK_FILTER_NEAREST;
        mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        mipLodBias = 0.0f;
        anisotropyEnable = VK_FALSE;
        maxAnisotropy = 0.0f;
        compareEnable = VK_FALSE;
        compareOp = VK_COMPARE_OP_NEVER;
        minLod = 0.0f;
        maxLod = 0.0f;
        borderColor = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
        unnormalizedCoordinates = VK_FALSE;
    }
};


//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    VkInstance*                                 pInstance);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyInstance(
    VkInstance                                  instance);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumeratePhysicalDevices(
    VkInstance                                  instance,
    std::vector<VkPhysicalDevice>*              pPhysicalDevices);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkQueueFamilyProperties>*       pQueueFamilyProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    VkDevice*                                   pDevice);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDevice(
    VkDevice                                    device);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const VkSubmitInfo*                         pSubmit,
    VkFence                                     fence);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const std::vector<VkSubmitInfo>*            pSubmits,
    VkFence                                     fence);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    VkDeviceMemory*                             pMemory);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    void**                                      ppData);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    VkFence*                                    pFence);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    VkSemaphore*                                pSemaphore);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    VkEvent*                                    pEvent);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    VkQueryPool*                                pQueryPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    VkBuffer*                                   pBuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    VkBufferView*                               pView);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    VkImage*                                    pImage);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyImage(
    VkDevice                                    device,
    VkImage                                     image);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    VkImageView*                                pView);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModule*                             pShaderModule);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    VkPipelineCache*                            pPipelineCache);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    VkPipeline*                                 pPipelines);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    VkPipeline*                                 pPipelines);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    VkPipelineLayout*                           pPipelineLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    VkSampler*                                  pSampler);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayout*                      pSetLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    VkDescriptorPool*                           pDescriptorPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    VkFramebuffer*                              pFramebuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    VkRenderPass*                               pRenderPass);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    VkCommandPool*                              pCommandPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffer(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkCommandBuffer*                      pCommandBuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const std::vector<VkCommandBuffer>*         pCommandBuffers);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const VkBufferCopy*                         pRegion);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferCopy>*            pRegions);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageCopy*                          pRegion);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkImageCopy>*             pRegions);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageBlit*                          pRegion,
    VkFilter                                    filter);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkImageBlit>*             pRegions,
    VkFilter                                    filter);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkBufferImageCopy*                    pRegion);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkBufferImageCopy>*       pRegions);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const VkBufferImageCopy*                    pRegion);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferImageCopy>*       pRegions);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const VkImageMemoryBarrier*                 pImageMemoryBarrier);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const std::vector<VkImageMemoryBarrier>*    pImageMemoryBarriers);

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

#endif  // VKUT_VKUT_H_

// clang-format on
