//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

#ifndef VKUT_VKUT_H_
#define VKUT_VKUT_H_

#pragma warning(disable : 26812)

#ifdef VK_NO_PROTOTPYES
#error
#endif

#include <vulkan/vulkan.h>

#include <vector>

//-----------------------------------------------------------------------------

struct VkutApplicationInfo : VkApplicationInfo {
    VkutApplicationInfo() {
        sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        pNext = nullptr;
        pApplicationName = nullptr;
        applicationVersion = VK_MAKE_VERSION(0, 0, 0);
        pEngineName = nullptr;
        engineVersion = VK_MAKE_VERSION(0, 0, 0);
        apiVersion = VK_API_VERSION_1_0;
    }
};

//-----------------------------------------------------------------------------

struct VkutInstanceCreateInfo : VkInstanceCreateInfo {
    VkutInstanceCreateInfo() {
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

struct VkutExtent3D : VkExtent3D {
    VkutExtent3D() {
        width = 0;
        height = 0;
        depth = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutDeviceQueueCreateInfo : VkDeviceQueueCreateInfo {
    VkutDeviceQueueCreateInfo() {
        sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queueFamilyIndex = 0;
        queueCount = 0;
        pQueuePriorities = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VkutDeviceCreateInfo : VkDeviceCreateInfo {
    VkutDeviceCreateInfo() {
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

struct VkutSubmitInfo : VkSubmitInfo {
    VkutSubmitInfo() {
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

struct VkutMemoryAllocateInfo : VkMemoryAllocateInfo {
    VkutMemoryAllocateInfo() {
        sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        pNext = nullptr;
        allocationSize = 0;
        memoryTypeIndex = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutMappedMemoryRange : VkMappedMemoryRange {
    VkutMappedMemoryRange() {
        sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
        pNext = nullptr;
        memory = VK_NULL_HANDLE;
        offset = 0;
        size = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutBindSparseInfo : VkBindSparseInfo {
    VkutBindSparseInfo() {
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

struct VkutFenceCreateInfo : VkFenceCreateInfo {
    VkutFenceCreateInfo() {
        sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutSemaphoreCreateInfo : VkSemaphoreCreateInfo {
    VkutSemaphoreCreateInfo() {
        sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutEventCreateInfo : VkEventCreateInfo {
    VkutEventCreateInfo() {
        sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutQueryPoolCreateInfo : VkQueryPoolCreateInfo {
    VkutQueryPoolCreateInfo() {
        sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        queryType = VK_QUERY_TYPE_OCCLUSION;
        queryCount = 0;
        pipelineStatistics = 0;
    }
};

//-----------------------------------------------------------------------------

struct VkutBufferCreateInfo : VkBufferCreateInfo {
    VkutBufferCreateInfo() {
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

struct VkutBufferViewCreateInfo : VkBufferViewCreateInfo {
    VkutBufferViewCreateInfo() {
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

struct VkutImageCreateInfo : VkImageCreateInfo {
    VkutImageCreateInfo() {
        sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        pNext = nullptr;
        flags = 0;
        imageType = VK_IMAGE_TYPE_1D;
        format = VK_FORMAT_UNDEFINED;
        extent = VkutExtent3D();
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

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    VkInstance*                                 pInstance);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyInstance(
    VkInstance                                  instance);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    VkDevice*                                   pDevice);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyDevice(
    VkDevice                                    device);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    VkDeviceMemory*                             pMemory);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    VkFence*                                    pFence);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    VkSemaphore*                                pSemaphore);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    VkEvent*                                    pEvent);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    VkQueryPool*                                pQueryPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    VkBuffer*                                   pBuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    VkBufferView*                               pView);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    VkImage*                                    pImage);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyImage(
    VkDevice                                    device,
    VkImage                                     image);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    VkImageView*                                pView);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModule*                             pShaderModule);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    VkPipelineCache*                            pPipelineCache);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    VkPipeline*                                 pPipelines);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    VkPipeline*                                 pPipelines);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    VkPipelineLayout*                           pPipelineLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    VkSampler*                                  pSampler);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayout*                      pSetLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    VkDescriptorPool*                           pDescriptorPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    VkFramebuffer*                              pFramebuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    VkRenderPass*                               pRenderPass);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vkutCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    VkCommandPool*                              pCommandPool);

//-----------------------------------------------------------------------------

VKAPI_ATTR void VKAPI_CALL vkutDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool);

//-----------------------------------------------------------------------------

#endif  // VKUT_VKUT_H_

