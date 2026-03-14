#pragma once
#include "../../../renderer/render_context.h"
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
    private:
        GLFWwindow* window;
        // Vulkan 上下文
        vk::raii::Context context;
        vk::raii::Instance instance = nullptr;
    };
}