#pragma once
#include "../../../renderer/render_context.h"
#include "vulkan/vulkan.hpp"
#include <vector>
#include <vulkan/vulkan_raii.hpp>
#include <GLFW/glfw3.h>

namespace azer {
    class VulkanRenderContext : public RenderContext {
    public:
        VulkanRenderContext(void* window_handle);
        ~VulkanRenderContext();

        void init() override;

    private:
        void create_instance();
        std::vector<const char*> get_required_extensions();
        std::vector<const char*> get_required_layers();

        // 验证层回调函数
        static VKAPI_ATTR vk::Bool32 VKAPI_CALL debug_callback(
            vk::DebugUtilsMessageSeverityFlagBitsEXT       severity,
            vk::DebugUtilsMessageTypeFlagsEXT              type,
            const vk::DebugUtilsMessengerCallbackDataEXT*  pCallbackData,
            void *                                         pUserData)
        {
            std::cerr << "validation layer: type " << to_string(type) << " msg: " << pCallbackData->pMessage << std::endl;
            return vk::False;
        }

        void setup_debug_messenger();
        void pick_physical_device();
        bool is_device_suitable(const vk::raii::PhysicalDevice& physical_device);
    private:
        GLFWwindow* window;
        // Vulkan 上下文
        vk::raii::Context context;
        vk::raii::Instance instance = nullptr;
        vk::raii::DebugUtilsMessengerEXT debug_messenger = nullptr;
        vk::raii::PhysicalDevice physical_device = nullptr;
    };
}