#include "azpch.h"

#include "core/application.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    try {
        azer::Application app;
        app.run();
    } catch (const vk::SystemError& err) {
        std::cerr << "Vulkan error: " << err.what() << std::endl;
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "Application failed: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}