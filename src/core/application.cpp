#include "azpch.h"
#include "application.h"
#include "GLFW/glfw3.h"

namespace azer {

    constexpr uint32_t WIDTH = 1280;
    constexpr uint32_t HEIGHT = 720;

    Application::Application() {
        /* Initialize the library */
        if (!glfwInit())
            assert(false);

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Learn", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            assert(false);
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        render_context = RenderContext::Create((void*)window);
        render_context->init();
    }

    Application::~Application() {
        glfwDestroyWindow(window);
        glfwTerminate();
        window = nullptr;
    }
    
    void Application::run() {
        while (!glfwWindowShouldClose(window)) {
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
}