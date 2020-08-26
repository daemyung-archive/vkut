# 🌋 VKUT

## Purpose

VKUT is a utility for Vulkan and it help you reduce typing code to use Vulkan. As you know, Vulkan requires to write a lot of code to you and it's not fun. You can enjoy writing code with VKUT. It's written in C++ and supports all platforms.

## Build

First, you need to download VKUT in your project.

```
git clone https://github.com/daemyung/vkut.git
```

Second, you need to modify your CMakeLists.txt.

```
add_subdirectory(vkut)

target_link_libraries(${TARGET_NAME}
  PUBLIC
    vkut
)
```

## Usage

Using VKUT is very similar to Vulkan. You need to keep in mind that all functions has `vkut` prefix and all structure has `Vkut` prefix.

```
// Set up the application info.
VkutApplicationInfo app_info;

app_info.SetEngineInfo("vulkan engine", 0, 1, 0);

// Set up the instance create info.
VkutInstanceCreateInfo create_info;

create_info.pApplicationInfo = &app_info;
create_info.SetEnabledLayerNames(layer_names);
create_info.SetEnabledExtensionNames(extension_names);

VkInstance instance;
vkutCreateInstance(create_info, instance);
```

It allow you to call a function once to query what you need.

```
std::vector<VkPhysicalDevice> physical_devices;
vkutEnumeratePhysicalDevices(instance, physical_devices);
```

It supports convenience utility functions. You can easily get what you want.

```
VkPhysicalDevice physical_device;
vkutFindBestPhysicalDevice(instance_, physical_device);
```

## License

This library is available to anybody free of charge, under the terms of GNU General Public License(see LICENSE.md).
