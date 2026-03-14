#include "vulkan_render_context.h"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan.hpp"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace azer {

    const std::vector<const char*> validation_layers = {
        "VK_LAYER_KHRONOS_validation",
    };

    #ifdef NDEBUG
    constexpr bool enable_validation_layer = false;
    #else
    constexpr bool enable_validation_layer = true;
    #endif

    VulkanRenderContext::VulkanRenderContext(void* window_handle) {
        window = (GLFWwindow*)window_handle;
    }

    VulkanRenderContext::~VulkanRenderContext() {
    }

    void VulkanRenderContext::init() {
        create_instance();
    }
    
    // 创建 Vulkan 实例
    void VulkanRenderContext::create_instance() {
        constexpr vk::ApplicationInfo app_info {
            "Vulkan Learn",
            VK_MAKE_VERSION(1, 0, 0),
            "No Engine",
            VK_MAKE_VERSION(1, 0, 0),
            vk::ApiVersion14,
        };

        std::vector<const char*> required_layers = get_required_layers();
        std::vector<const char*> required_extensions = get_required_extensions();

        vk::InstanceCreateInfo create_info {};
        create_info.pApplicationInfo = &app_info;
        create_info.enabledLayerCount = static_cast<uint32_t>(required_layers.size());
        create_info.ppEnabledLayerNames = required_layers.data();
        create_info.enabledExtensionCount = static_cast<uint32_t>(required_extensions.size());
        create_info.ppEnabledExtensionNames = required_extensions.data();

        instance = vk::raii::Instance(context, create_info);
    }

    // 获取所有需要的扩展
    std::vector<const char*> VulkanRenderContext::get_required_extensions() {
        std::vector<const char*> required_extensions;
        uint32_t glfw_extension_count = 0;
        auto glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

        auto extension_properties = context.enumerateInstanceExtensionProperties();
        for (uint32_t i = 0; i < glfw_extension_count; i++) {
            if (std::ranges::none_of(extension_properties,
                [glfw_extension = glfw_extensions[i]](auto const& extension_property){
                    return strcmp(extension_property.extensionName, glfw_extension) == 0;
                })) {
                    throw std::runtime_error("Required GLFW extension not supported: " + std::string(glfw_extensions[i]));
                }
        }
        required_extensions.assign(glfw_extensions, glfw_extensions + glfw_extension_count);
        return required_extensions;
    }
    
    // 启用验证层
    std::vector<const char*> VulkanRenderContext::get_required_layers() {
        std::vector<const char*> required_layers;
        if (enable_validation_layer) {
            required_layers.assign(validation_layers.begin(), validation_layers.end());
        }

        // 检查所需验证层是否被Vulkan实现支持
        auto layer_properties = context.enumerateInstanceLayerProperties();
        auto unsupported_layer_it = std::ranges::find_if(required_layers,
            [&layer_properties](auto const& required_layer) {
                return std::ranges::none_of(layer_properties,
                    [required_layer](auto const& layer_property){
                        return strcmp(layer_property.layerName, required_layer) == 0;
                    });
            });
        if (unsupported_layer_it != required_layers.end()) {
            throw std::runtime_error("Required validation layer not supported: " + std::string(*unsupported_layer_it));
        }
        return required_layers;
    }
}