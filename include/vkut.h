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

    void SetEnabledLayerName(const char*& pName) {
        enabledLayerCount = 1;
        ppEnabledLayerNames = &pName;
    }

    template<typename T>
    void SetEnabledLayerNames(T count, const char** ppNames) {
        enabledLayerCount = static_cast<uint32_t>(count);
        ppEnabledLayerNames = ppNames;
    }

    void SetEnabledLayerNames(std::vector<const char*>& names) {
        enabledLayerCount = static_cast<uint32_t>(names.size());
        ppEnabledLayerNames = names.data();
    }

    void SetEnabledExtensionName(const char*& pName) {
        enabledExtensionCount = 1;
        ppEnabledExtensionNames = &pName;
    }

    template<typename T>
    void SetEnabledExtensionNames(T count, const char** ppNames) {
        enabledExtensionCount = static_cast<uint32_t>(count);
        ppEnabledExtensionNames = ppNames;
    }

    void SetEnabledExtensionNames(std::vector<const char*>& names) {
        enabledExtensionCount = static_cast<uint32_t>(names.size());
        ppEnabledExtensionNames = names.data();
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
        sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queueFamilyIndex = 0;
        queueCount = 0;
        pQueuePriorities = nullptr;
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

VKAPI_ATTR VkResult VKAPI_CALL vuCreateInstance(
    const VkInstanceCreateInfo&                 createInfo,
    VkInstance&                                 instance);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyInstance(
    VkInstance                                  instance);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumeratePhysicalDevices(
    VkInstance                                  instance,
    std::vector<VkPhysicalDevice>&              physicalDevices);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkQueueFamilyProperties>&       queueFamilyProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    VkDevice*                                   pDevice);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vuDestroyDevice(
    VkDevice                                    device);

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

VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceScore(
    VkPhysicalDevice                            physicalDevice,
    uint32_t&                                   score);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuFindBestPhysicalDevice(
    VkInstance                                  instance,
    VkPhysicalDevice&                           physicalDevice);

//-----------------------------------------------------------------------------

#endif  // VKUT_VKUT_H_

// clang-format on
