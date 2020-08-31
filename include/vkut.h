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
        this->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        this->pNext = nullptr;
        this->pApplicationName = nullptr;
        this->applicationVersion = VK_MAKE_VERSION(0, 0, 0);
        this->pEngineName = nullptr;
        this->engineVersion = VK_MAKE_VERSION(0, 0, 0);
        this->apiVersion = VK_API_VERSION_1_0;
    }

    VuApplicationInfo& SetApplicationInfo(const char* pName, uint8_t major, uint32_t minor, uint32_t patch) {
        this->pApplicationName = pName;
        this->applicationVersion = VK_MAKE_VERSION(major, minor, patch);

        return *this;
    }

    VuApplicationInfo& SetEngineInfo(const char* pName, uint8_t major, uint32_t minor, uint32_t patch) {
        this->pEngineName = pName;
        this->engineVersion = VK_MAKE_VERSION(major, minor, patch);

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuInstanceCreateInfo : VkInstanceCreateInfo {
    VuInstanceCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->pApplicationInfo = nullptr;
        this->enabledLayerCount = 0;
        this->ppEnabledLayerNames = nullptr;
        this->enabledExtensionCount = 0;
        this->ppEnabledExtensionNames = nullptr;
    }

    VuInstanceCreateInfo& SetEnabledLayerName(const char** ppName) {
        this->enabledLayerCount = 1;
        this->ppEnabledLayerNames = ppName;

        return *this;
    }

    VuInstanceCreateInfo& SetEnabledLayerNames(const std::vector<const char*>* pNames) {
        this->enabledLayerCount = static_cast<uint32_t>(pNames->size());
        this->ppEnabledLayerNames = pNames->data();

        return *this;
    }

    VuInstanceCreateInfo& SetEnabledExtensionName(const char** ppName) {
        this->enabledExtensionCount = 1;
        this->ppEnabledExtensionNames = ppName;

        return *this;
    }

    VuInstanceCreateInfo& SetEnabledExtensionNames(const std::vector<const char*>* pNames) {
        this->enabledExtensionCount = static_cast<uint32_t>(pNames->size());
        this->ppEnabledExtensionNames = pNames->data();

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuExtent2D : VkExtent2D {
    VuExtent2D() {
        this->width = 0;
        this->height = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuExtent3D : VkExtent3D {
    VuExtent3D() {
        this->width = 0;
        this->height = 0;
        this->depth = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuDeviceQueueCreateInfo : VkDeviceQueueCreateInfo {
    VuDeviceQueueCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->queueFamilyIndex = 0;
        this->queueCount = 0;
        this->pQueuePriorities = nullptr;
    }

    VuDeviceQueueCreateInfo& SetQueueFamilyIndex(uint32_t familyIndex) {
        this->queueFamilyIndex = familyIndex;

        return *this;
    }

    VuDeviceQueueCreateInfo& SetQueueInfo(uint32_t count, const float* pPriorities) {
        this->queueCount = count;
        this->pQueuePriorities = pPriorities;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuDeviceCreateInfo : VkDeviceCreateInfo {
    VuDeviceCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->queueCreateInfoCount = 0;
        this->pQueueCreateInfos = nullptr;
        this->enabledLayerCount = 0;
        this->ppEnabledLayerNames = nullptr;
        this->enabledExtensionCount = 0;
        this->ppEnabledExtensionNames = nullptr;
        this->pEnabledFeatures = nullptr;
    }

    VuDeviceCreateInfo& SetQueueCreateInfo(const VkDeviceQueueCreateInfo* pCreateInfo) {
        this->queueCreateInfoCount = 1;
        this->pQueueCreateInfos = pCreateInfo;

        return *this;
    }

    VuDeviceCreateInfo& SetQueueCreateInfos(const std::vector<VkDeviceQueueCreateInfo>* pCreateInfos) {
        this->queueCreateInfoCount = static_cast<uint32_t>(pCreateInfos->size());
        this->pQueueCreateInfos = pCreateInfos->data();

        return *this;
    }

    VuDeviceCreateInfo& SetEnabledExtensionName(const char** ppName) {
        this->enabledExtensionCount = 1;
        this->ppEnabledExtensionNames = ppName;

        return *this;
    }

    VuDeviceCreateInfo& SetEnabledExtensionNames(const std::vector<const char*>* pNames) {
        this->enabledExtensionCount = static_cast<uint32_t>(pNames->size());
        this->ppEnabledExtensionNames = pNames->data();

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuSubmitInfo : VkSubmitInfo {
    VuSubmitInfo() {
        this->sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        this->pNext = nullptr;
        this->waitSemaphoreCount = 0;
        this->pWaitSemaphores = nullptr;
        this->pWaitDstStageMask = nullptr;
        this->commandBufferCount = 0;
        this->pCommandBuffers = nullptr;
        this->signalSemaphoreCount = 0;
        this->pSignalSemaphores = nullptr;
    }

    VuSubmitInfo& SetCommandBuffer(const VkCommandBuffer* pCommandBuffer) {
        this->commandBufferCount = 1;
        this->pCommandBuffers = pCommandBuffer;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuMemoryAllocateInfo : VkMemoryAllocateInfo {
    VuMemoryAllocateInfo() {
        this->sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        this->pNext = nullptr;
        this->allocationSize = 0;
        this->memoryTypeIndex = 0;
    }

    VuMemoryAllocateInfo& SetAllocationSize(VkDeviceSize allocationSize) {
        this->allocationSize = allocationSize;

        return *this;
    }

    VuMemoryAllocateInfo& SetMemoryTypeIndex(uint32_t memoryTypeIndex) {
        this->memoryTypeIndex = memoryTypeIndex;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuMappedMemoryRange : VkMappedMemoryRange {
    VuMappedMemoryRange() {
        this->sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
        this->pNext = nullptr;
        this->memory = VK_NULL_HANDLE;
        this->offset = 0;
        this->size = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuBindSparseInfo : VkBindSparseInfo {
    VuBindSparseInfo() {
        this->sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
        this->pNext = nullptr;
        this->waitSemaphoreCount = 0;
        this->pWaitSemaphores = nullptr;
        this->bufferBindCount = 0;
        this->pBufferBinds = nullptr;
        this->imageOpaqueBindCount = 0;
        this->pImageOpaqueBinds = nullptr;
        this->imageBindCount = 0;
        this->pImageBinds = nullptr;
        this->signalSemaphoreCount = 0;
        this->pSignalSemaphores = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VuFenceCreateInfo : VkFenceCreateInfo {
    VuFenceCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuSemaphoreCreateInfo : VkSemaphoreCreateInfo {
    VuSemaphoreCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuEventCreateInfo : VkEventCreateInfo {
    VuEventCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuQueryPoolCreateInfo : VkQueryPoolCreateInfo {
    VuQueryPoolCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->queryType = VK_QUERY_TYPE_OCCLUSION;
        this->queryCount = 0;
        this->pipelineStatistics = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuBufferCreateInfo : VkBufferCreateInfo {
    VuBufferCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->size = 0;
        this->usage = 0;
        this->sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        this->queueFamilyIndexCount = 0;
        this->pQueueFamilyIndices = nullptr;
    }

    VuBufferCreateInfo& SetSize(VkDeviceSize size) {
        this->size = size;

        return *this;
    }

    VuBufferCreateInfo& SetUsage(VkBufferUsageFlags usage) {
        this->usage = usage;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuBufferViewCreateInfo : VkBufferViewCreateInfo {
    VuBufferViewCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->buffer = VK_NULL_HANDLE;
        this->format = VK_FORMAT_UNDEFINED;
        this->offset = 0;
        this->range = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuImageCreateInfo : VkImageCreateInfo {
    VuImageCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->imageType = VK_IMAGE_TYPE_1D;
        this->format = VK_FORMAT_UNDEFINED;
        this->extent = VuExtent3D();
        this->mipLevels = 1;
        this->arrayLayers = 1;
        this->samples = VK_SAMPLE_COUNT_1_BIT;
        this->usage = 0;
        this->sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        this->queueFamilyIndexCount = 0;
        this->pQueueFamilyIndices = nullptr;
        this->initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    }
};

//-----------------------------------------------------------------------------

struct VuComponentMapping : VkComponentMapping {
    VuComponentMapping() {
        this->r = VK_COMPONENT_SWIZZLE_IDENTITY;
        this->g = VK_COMPONENT_SWIZZLE_IDENTITY;
        this->b = VK_COMPONENT_SWIZZLE_IDENTITY;
        this->a = VK_COMPONENT_SWIZZLE_IDENTITY;
    }
};

//-----------------------------------------------------------------------------

struct VuImageSubresourceRange : VkImageSubresourceRange {
    VuImageSubresourceRange() {
        this->aspectMask = 0;
        this->baseMipLevel = 0;
        this->levelCount = 0;
        this->baseArrayLayer = 0;
        this->layerCount = 0;
    }
};

//-----------------------------------------------------------------------------

struct VuImageViewCreateInfo : VkImageViewCreateInfo {
    VuImageViewCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->image = VK_NULL_HANDLE;
        this->viewType = VK_IMAGE_VIEW_TYPE_1D;
        this->format = VK_FORMAT_UNDEFINED;
        this->components = VuComponentMapping();
        this->subresourceRange = VuImageSubresourceRange();
    }
};

//-----------------------------------------------------------------------------

struct VuCommandPoolCreateInfo : VkCommandPoolCreateInfo {
    VuCommandPoolCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->queueFamilyIndex = 0;
    }

    VuCommandPoolCreateInfo& SetFlags(VkCommandPoolCreateFlags flags) {
        this->flags = flags;

        return *this;
    }

    VuCommandPoolCreateInfo& SetQueueFamilyIndex(uint32_t queueFamilyIndex) {
        this->queueFamilyIndex = queueFamilyIndex;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuCommandBufferAllocateInfo : VkCommandBufferAllocateInfo {
    VuCommandBufferAllocateInfo() {
        this->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        this->pNext = nullptr;
        this->commandPool = VK_NULL_HANDLE;
        this->level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        this->commandBufferCount = 0;
    }

    VuCommandBufferAllocateInfo& SetCommandPool(VkCommandPool commandPool) {
        this->commandPool = commandPool;

        return *this;
    }

    VuCommandBufferAllocateInfo& SetCommandBufferInfo(VkCommandBufferLevel level, uint32_t count) {
        this->level = level;
        this->commandBufferCount = count;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuCommandBufferBeginInfo : VkCommandBufferBeginInfo {
    VuCommandBufferBeginInfo() {
        this->sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->pInheritanceInfo = nullptr;
    }
};

//-----------------------------------------------------------------------------

struct VuImageMemoryBarrier : VkImageMemoryBarrier {
    VuImageMemoryBarrier() {
        this->sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        this->pNext = nullptr;
        this->srcAccessMask = 0;
        this->dstAccessMask = 0;
        this->oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        this->newLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        this->srcQueueFamilyIndex = 0;
        this->dstQueueFamilyIndex = 0;
        this->image = VK_NULL_HANDLE;
        this->subresourceRange = VuImageSubresourceRange();
    }

    VuImageMemoryBarrier& SetQueueFamilyIndex(uint32_t queueFamilyIndex) {
        this->srcQueueFamilyIndex = queueFamilyIndex;
        this->dstQueueFamilyIndex = queueFamilyIndex;

        return *this;
    }
};

//-----------------------------------------------------------------------------

struct VuSamplerCreateInfo : VkSamplerCreateInfo {
    VuSamplerCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        this->pNext = nullptr;
        this->flags = 0;
        this->magFilter = VK_FILTER_NEAREST;
        this->minFilter = VK_FILTER_NEAREST;
        this->mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        this->addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        this->addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        this->addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        this->mipLodBias = 0.0f;
        this->anisotropyEnable = VK_FALSE;
        this->maxAnisotropy = 0.0f;
        this->compareEnable = VK_FALSE;
        this->compareOp = VK_COMPARE_OP_NEVER;
        this->minLod = 0.0f;
        this->maxLod = 0.0f;
        this->borderColor = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
        this->unnormalizedCoordinates = VK_FALSE;
    }
};

//-----------------------------------------------------------------------------

struct VuSwapchainCreateInfo : VkSwapchainCreateInfoKHR {
    VuSwapchainCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        this->pNext = nullptr;
        this->flags = 0;
        this->surface = VK_NULL_HANDLE;
        this->minImageCount = 0;
        this->imageFormat = VK_FORMAT_UNDEFINED;
        this->imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        this->imageExtent = VuExtent2D();
        this->imageArrayLayers = 1;
        this->imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        this->imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        this->queueFamilyIndexCount = 0;
        this->pQueueFamilyIndices = nullptr;
        this->preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
        this->compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        this->presentMode = VK_PRESENT_MODE_FIFO_KHR;
        this->clipped = VK_TRUE;
        this->oldSwapchain = VK_NULL_HANDLE;
    }

    VuSwapchainCreateInfo& SetSurface(VkSurfaceKHR surface) {
        this->surface = surface;

        return *this;
    }

    VuSwapchainCreateInfo& SetMinImageCount(uint32_t minImageCount) {
        this->minImageCount = minImageCount;

        return *this;
    }

    VuSwapchainCreateInfo& SetImageFormat(VkFormat imageFormat) {
        this->imageFormat = imageFormat;

        return *this;
    }

    VuSwapchainCreateInfo& SetImageExtent(uint32_t width, uint32_t height) {
        this->imageExtent.width = width;
        this->imageExtent.height = height;

        return *this;
    }
};

//-----------------------------------------------------------------------------

#ifdef VK_USE_PLATFORM_MACOS_MVK
struct VuMacOSSurfaceCreateInfo : VkMacOSSurfaceCreateInfoMVK {
    VuMacOSSurfaceCreateInfo() {
        this->sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
        this->pNext = nullptr;
        this->flags = 0;
        this->pView = nullptr;
    }

    VuMacOSSurfaceCreateInfo& SetView(void* pView) {
        this->pView = pView;

        return *this;
    }
};
#endif

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

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
    std::vector<VkExtensionProperties>*         pProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
    const char*                                 pLayerName,
    std::vector<VkExtensionProperties>*         pProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkExtensionProperties>*         pProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    const char*                                 pLayerName,
    std::vector<VkExtensionProperties>*         pProperties);

//-----------------------------------------------------------------------------

VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceLayerProperties(
    std::vector<VkLayerProperties>*             pProperties);

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

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateSwapchain(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    VkSwapchainKHR*                             pSwapchain) {
    return vkCreateSwapchainKHR(device, pCreateInfo, nullptr, pSwapchain);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroySwapchain(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain) {
    vkDestroySwapchainKHR(device, swapchain, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuGetSwapchainImages(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    std::vector<VkImage>*                       pSwapchainImages) {
    // Initialize out parameters.
    pSwapchainImages->clear();

    // Get all swapchain images.
    VkResult status;

    uint32_t count;
    status = vkGetSwapchainImagesKHR(device, swapchain, &count, nullptr);

    if (status != VK_SUCCESS)
        return status;

    pSwapchainImages->resize(count);
    status = vkGetSwapchainImagesKHR(device, swapchain, &count, pSwapchainImages->data());

    return status;
}

//-----------------------------------------------------------------------------

#ifdef VK_USE_PLATFORM_MACOS_MVK
inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateMacOSSurface(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    VkSurfaceKHR*                               pSurface) {
    return vkCreateMacOSSurfaceMVK(instance, pCreateInfo, nullptr, pSurface);
}
#endif

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

#endif  // VKUT_VKUT_H_

// clang-format on
