//
// This file is part of the "vkut" project
// See "LICENSE" for license information.
//

// clang-format off
#ifndef VKUT_CORE_H_
#define VKUT_CORE_H_

#pragma warning(push)
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

    VuSubmitInfo& SetWaitSemaphore(const VkSemaphore* pWaitSemaphore, const VkPipelineStageFlags* pWaitDstStageMask ) {
        this->waitSemaphoreCount = 1;
        this->pWaitSemaphores = pWaitSemaphore;
        this->pWaitDstStageMask = pWaitDstStageMask;

        return *this;
    }

    VuSubmitInfo& SetCommandBuffer(const VkCommandBuffer* pCommandBuffer) {
        this->commandBufferCount = 1;
        this->pCommandBuffers = pCommandBuffer;

        return *this;
    }

    VuSubmitInfo& SetSignalSemaphore(const VkSemaphore* pSignalSemaphore) {
        this->signalSemaphoreCount = 1;
        this->pSignalSemaphores = pSignalSemaphore;

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

    VuFenceCreateInfo& SetFlags(VkFenceCreateFlags flags) {
        this->flags = flags;

        return *this;
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

    VuImageCreateInfo& SetImageType(VkImageType imageType) {
        this->imageType = imageType;

        return *this;
    }

    VuImageCreateInfo& SetFormat(VkFormat format) {
        this->format = format;

        return *this;
    }

    VuImageCreateInfo& SetExtent(uint32_t width, uint32_t height) {
        this->extent.width = width;
        this->extent.height = height;
        this->extent.depth = 1;

        return *this;
    }

    VuImageCreateInfo& SetUsage(VkImageUsageFlags usage) {
        this->usage = usage;

        return *this;
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
        this->levelCount = 1;
        this->baseArrayLayer = 0;
        this->layerCount = 1;
    }

    VuImageSubresourceRange& SetAspectMask(VkImageAspectFlags aspectMask) {
        this->aspectMask = aspectMask;

        return *this;
    }

    VuImageSubresourceRange& SetBaseMipLevel(uint32_t baseMipLevel) {
        this->baseMipLevel = baseMipLevel;

        return *this;
    }

    VuImageSubresourceRange& SetLevelCount(uint32_t levelCount) {
        this->levelCount = levelCount;

        return *this;
    }

    VuImageSubresourceRange& SetBaseArrayLayer(uint32_t baseArrayLayer) {
        this->baseArrayLayer = baseArrayLayer;

        return *this;
    }

    VuImageSubresourceRange& SetLayerCount(uint32_t layerCount) {
        this->layerCount = layerCount;

        return *this;
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

    VuImageViewCreateInfo& SetImage(VkImage image) {
        this->image = image;

        return *this;
    }

    VuImageViewCreateInfo& SetViewType(VkImageViewType viewType) {
        this->viewType = viewType;

        return *this;
    }

    VuImageViewCreateInfo& SetFormat(VkFormat format) {
        this->format = format;

        return *this;
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

    VuImageMemoryBarrier& SetAccessMask(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask) {
        this->srcAccessMask = srcAccessMask;
        this->dstAccessMask = dstAccessMask;

        return *this;
    }

    VuImageMemoryBarrier& SetImageLayout(VkImageLayout oldLayout, VkImageLayout newLayout) {
        this->oldLayout = oldLayout;
        this->newLayout = newLayout;

        return *this;
    }

    VuImageMemoryBarrier& SetQueueFamilyIndex(uint32_t queueFamilyIndex) {
        this->srcQueueFamilyIndex = queueFamilyIndex;
        this->dstQueueFamilyIndex = queueFamilyIndex;

        return *this;
    }

    VuImageMemoryBarrier& SetImage(VkImage image) {
        this->image = image;

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

struct VuPresentInfo : VkPresentInfoKHR {
    VuPresentInfo() {
        this->sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
        this->pNext = nullptr;
        this->waitSemaphoreCount = 0;
        this->pWaitSemaphores = nullptr;
        this->swapchainCount = 0;
        this->pSwapchains = nullptr;
        this->pImageIndices = nullptr;
        this->pResults = nullptr;
    }

    VuPresentInfo& SetWaitSemaphore(const VkSemaphore* pWaitSemaphore) {
        this->waitSemaphoreCount = 1;
        this->pWaitSemaphores = pWaitSemaphore;

        return *this;
    }

    VuPresentInfo& SetSwapchainInfo(const VkSwapchainKHR* pSwapchain, const uint32_t* pImageIndex) {
        this->swapchainCount = 1;
        this->pSwapchains = pSwapchain;
        this->pImageIndices = pImageIndex;

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

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    VkInstance*                                 pInstance) {
    return vkCreateInstance(pCreateInfo, nullptr, pInstance);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyInstance(
    VkInstance                                  instance) {
    vkDestroyInstance(instance, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumeratePhysicalDevices(
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

inline VKAPI_ATTR void VKAPI_CALL vuGetPhysicalDeviceQueueFamilyProperties(
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

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    VkDevice*                                   pDevice) {
    return vkCreateDevice(physicalDevice, pCreateInfo, nullptr, pDevice);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyDevice(
    VkDevice                                    device) {
    vkDestroyDevice(device, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
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

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceExtensionProperties(
    std::vector<VkExtensionProperties>*         pProperties) {
    return vuEnumerateInstanceExtensionProperties(nullptr, pProperties);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
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

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateDeviceExtensionProperties(
    VkPhysicalDevice                            physicalDevice,
    std::vector<VkExtensionProperties>*         pProperties) {
    return vuEnumerateDeviceExtensionProperties(physicalDevice, nullptr, pProperties);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuEnumerateInstanceLayerProperties(
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

inline VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const VkSubmitInfo*                         pSubmit,
    VkFence                                     fence) {
    return vkQueueSubmit(queue, 1, pSubmit, fence);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuQueueSubmit(
    VkQueue                                     queue,
    const std::vector<VkSubmitInfo>*            pSubmits,
    VkFence                                     fence) {
    return vkQueueSubmit(queue, static_cast<uint32_t>(pSubmits->size()), pSubmits->data(), fence);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuAllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    VkDeviceMemory*                             pMemory) {
    return vkAllocateMemory(device, pAllocateInfo, nullptr, pMemory);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuFreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory) {
    vkFreeMemory(device, memory, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuMapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    void**                                      ppData) {
    return vkMapMemory(device, memory, 0, VK_WHOLE_SIZE, 0, ppData);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuBindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory) {
    return vkBindBufferMemory(device, buffer, memory, 0);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuBindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory) {
    return vkBindImageMemory(device, image, memory, 0);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    VkFence*                                    pFence) {
    return vkCreateFence(device, pCreateInfo, nullptr, pFence);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyFence(
    VkDevice                                    device,
    VkFence                                     fence) {
    vkDestroyFence(device, fence, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    VkSemaphore*                                pSemaphore) {
    return vkCreateSemaphore(device, pCreateInfo, nullptr, pSemaphore);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore) {
    vkDestroySemaphore(device, semaphore, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    VkEvent*                                    pEvent) {
    return vkCreateEvent(device, pCreateInfo, nullptr, pEvent);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event) {
    return vkDestroyEvent(device, event, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    VkQueryPool*                                pQueryPool) {
    return vkCreateQueryPool(device, pCreateInfo, nullptr, pQueryPool);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool) {
    vkDestroyQueryPool(device, queryPool, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    VkBuffer*                                   pBuffer) {
    return vkCreateBuffer(device, pCreateInfo, nullptr, pBuffer);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer) {
    vkDestroyBuffer(device, buffer, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    VkBufferView*                               pView) {
    return vkCreateBufferView(device, pCreateInfo, nullptr, pView);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView) {
    vkDestroyBufferView(device, bufferView, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    VkImage*                                    pImage) {
    return vkCreateImage(device, pCreateInfo, nullptr, pImage);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyImage(
    VkDevice                                    device,
    VkImage                                     image) {
    vkDestroyImage(device, image, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    VkImageView*                                pView) {
    return vkCreateImageView(device, pCreateInfo, nullptr, pView);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView) {
    vkDestroyImageView(device, imageView, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    VkShaderModule*                             pShaderModule) {
    return vkCreateShaderModule(device, pCreateInfo, nullptr, pShaderModule);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule) {
    vkDestroyShaderModule(device, shaderModule, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    VkPipelineCache*                            pPipelineCache) {
    return vkCreatePipelineCache(device, pCreateInfo, nullptr, pPipelineCache);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache) {
    vkDestroyPipelineCache(device, pipelineCache, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    VkPipeline*                                 pPipelines) {
    return vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, nullptr, pPipelines);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    VkPipeline*                                 pPipelines) {
    return vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, nullptr, pPipelines);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline) {
    vkDestroyPipeline(device, pipeline, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    VkPipelineLayout*                           pPipelineLayout) {
    return vkCreatePipelineLayout(device, pCreateInfo, nullptr, pPipelineLayout);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout) {
    vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    VkSampler*                                  pSampler) {
    return vkCreateSampler(device, pCreateInfo, nullptr, pSampler);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler) {
    vkDestroySampler(device, sampler, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayout*                      pSetLayout) {
    return vkCreateDescriptorSetLayout(device, pCreateInfo, nullptr, pSetLayout);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout) {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    VkDescriptorPool*                           pDescriptorPool) {
    return vkCreateDescriptorPool(device, pCreateInfo, nullptr, pDescriptorPool);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool) {
    vkDestroyDescriptorPool(device, descriptorPool, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    VkFramebuffer*                              pFramebuffer) {
    return vkCreateFramebuffer(device, pCreateInfo, nullptr, pFramebuffer);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer) {
    vkDestroyFramebuffer(device, framebuffer, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    VkRenderPass*                               pRenderPass) {
    return vkCreateRenderPass(device, pCreateInfo, nullptr, pRenderPass);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass) {
    vkDestroyRenderPass(device, renderPass, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR VkResult VKAPI_CALL vuCreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    VkCommandPool*                              pCommandPool) {
    return vkCreateCommandPool(device, pCreateInfo, nullptr, pCommandPool);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuDestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool) {
    vkDestroyCommandPool(device, commandPool, nullptr);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffer(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkCommandBuffer*                      pCommandBuffer) {
    vkFreeCommandBuffers(device, commandPool, 1, pCommandBuffer);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuFreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const std::vector<VkCommandBuffer>*         pCommandBuffers) {
    vkFreeCommandBuffers(device, commandPool, static_cast<uint32_t>(pCommandBuffers->size()), pCommandBuffers->data());
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const VkBufferCopy*                         pRegion) {
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, pRegion);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferCopy>*            pRegions) {
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkImageCopy*                          pRegion) {
    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, 1, pRegion);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkImageCopy>*             pRegions) {
    vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
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

inline VKAPI_ATTR void VKAPI_CALL vuCmdBlitImage(
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

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const VkBufferImageCopy*                    pRegion) {
    vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, 1, pRegion);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    const std::vector<VkBufferImageCopy>*       pRegions) {
    vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const VkBufferImageCopy*                    pRegion) {
    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, 1, pRegion);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    const std::vector<VkBufferImageCopy>*       pRegions) {
    vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, static_cast<uint32_t>(pRegions->size()), pRegions->data());
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const VkImageMemoryBarrier*                 pImageMemoryBarrier) {
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, 0, nullptr, 0, nullptr, 1, pImageMemoryBarrier);
}

//-----------------------------------------------------------------------------

inline VKAPI_ATTR void VKAPI_CALL vuCmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    const std::vector<VkImageMemoryBarrier>*    pImageMemoryBarriers) {
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, 0, nullptr, 0, nullptr, static_cast<uint32_t>(pImageMemoryBarriers->size()), pImageMemoryBarriers->data());
}

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

#pragma warning(pop)

#endif  // VKUT_CORE_H_

// clang-format on
