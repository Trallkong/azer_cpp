#pragma once

#include "base.h"


// TODO: 待分离
#include "../renderer/render_context.h"
#include <vulkan/vulkan_raii.hpp>
#include <GLFW/glfw3.h>

namespace azer {

    class Application {
    public:
        Application();
        ~Application();

        void run();
    private:
        bool is_running = true;

        GLFWwindow* window;
        scope<RenderContext> render_context;
    };

}


