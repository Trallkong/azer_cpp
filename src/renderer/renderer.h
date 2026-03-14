#pragma once
#include "../core/base.h"

namespace azer {
    class Renderer {
    public:
        enum class GraphicAPI {
            Vulkan,
            OpenGL,
            D3D12,
        };
        static GraphicAPI GetGraphicAPI() { return _api; }

    private:
        static GraphicAPI _api;
    };
}