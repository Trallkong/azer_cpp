#pragma once
#include "../core/base.h"

namespace azer {
    class RenderContext {
    public:
        virtual ~RenderContext() = default;

        virtual void init() = 0;

        static scope<RenderContext> Create(void* window_handle);
    };
}

