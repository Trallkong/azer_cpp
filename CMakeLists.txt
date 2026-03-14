cmake_minimum_required(VERSION 4.2)

project(Azer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Vulkan REQUIRED)

add_executable(Sandbox
    src/main.cpp
    src/azpch.h
    src/azpch.cpp
    
    src/core/base.h
    src/core/application.h
    src/core/application.cpp

    src/renderer/renderer.h
    src/renderer/renderer.cpp
    src/renderer/render_context.h
    src/renderer/render_context.cpp
    
    src/backends/platform/vulkan/vulkan_render_context.h
    src/backends/platform/vulkan/vulkan_render_context.cpp
)

target_compile_definitions(Sandbox PRIVATE
    AZER_WITH_VULKAN=1
)

target_include_directories(Sandbox PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Sandbox PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/lib-vc2022/glfw3.lib
    Vulkan::Vulkan
)

target_precompile_headers(Sandbox PRIVATE
    src/azpch.h
)