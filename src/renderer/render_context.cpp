#include "render_context.h"
#include <cassert>
#include "renderer.h"

#ifdef AZER_WITH_VULKAN
#include "../backends/platform/vulkan/vulkan_render_context.h"
#elif defined(AZER_WITH_OPENGL)
#include "../backends/platform/opengl/opengl_render_context.h"
#elif defined(AZER_WITH_D3D12)
#include "../backends/platform/d3d12/d3d12_render_context.h"
#else
#error "No render context available"
#endif

namespace azer {
    scope<RenderContext> RenderContext::Create(void* window_handle) {
        Renderer::GraphicAPI api = Renderer::GetGraphicAPI();
        switch (api) {
            #ifdef AZER_WITH_VULKAN
            case Renderer::GraphicAPI::Vulkan:
                return create_scope<VulkanRenderContext>(window_handle);
            #elif defined(AZER_WITH_OPENGL)
            case Renderer::GraphicAPI::OpenGL:
                return create_scope<OpenGLRenderContext>(window_handle);
            #elif defined(AZER_WITH_D3D12)
            case Renderer::GraphicAPI::D3D12:
                return create_scope<D3D12RenderContext>(window_handle);
            #endif
            default:
                assert(false);
                return nullptr;
        }
    }
}