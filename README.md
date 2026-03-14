# Azer

一个使用 Vulkan 图形 API 的图形渲染学习项目。

## 项目简介

Azer 是一个用于学习 Vulkan 图形编程的轻量级框架，采用现代化的 C++20 标准，提供了清晰的渲染抽象层。

## 技术栈

- **图形 API**: Vulkan (通过 vulkan.hpp RAII 接口)
- **窗口管理**: GLFW
- **C++ 标准**: C++20
- **构建系统**: CMake 4.2+
- **编译器**: MSVC 2022+

## 项目结构

```
Azer/
├── src/
│   ├── main.cpp                          # 程序入口
│   ├── azpch.h / azpch.cpp               # 预编译头文件
│   ├── core/
│   │   ├── base.h                        # 基础类型定义 (智能指针别名等)
│   │   ├── application.h/.cpp            # 应用程序核心类
│   ├── renderer/
│   │   ├── renderer.h/.cpp               # 渲染器抽象
│   │   ├── render_context.h/.cpp         # 渲染上下文工厂
│   └── backends/
│       └── platform/
│           ├── vulkan/                   # Vulkan 后端实现
│           ├── opengl/                   # OpenGL 后端 (待实现)
│           └── d3d12/                    # Direct3D 12 后端 (待实现)
├── lib/
│   └── glfw/                             # GLFW 库
└── CMakeLists.txt                        # 构建配置
```

## 功能特性

- ✅ 基于 Vulkan 的渲染上下文
- ✅ RAII 风格的资源管理
- ✅ 预编译头文件优化编译速度
- ✅ 多后端架构设计 (支持 Vulkan/OpenGL/D3D12)
- ✅ 现代化 C++20 特性

## 系统要求

- Windows 10/11
- Visual Studio 2022 或更高版本
- Vulkan SDK (1.3.x 或更高版本)
- CMake 4.2 或更高版本

## 构建说明

### 1. 安装依赖

确保已安装 Vulkan SDK：
- 下载地址：https://vulkan.lunarg.com/

### 2. 配置 CMake

```bash
mkdir build
cd build
cmake ..
```

### 3. 构建项目

```bash
cmake --build . --config Debug
```

或使用 Visual Studio:
1. 打开 CMake GUI
2. 选择项目目录
3. 点击 "Configure" 和 "Generate"
4. 在 Visual Studio 中打开生成的解决方案并构建

## 使用方法

```cpp
#include "core/application.h"

int main() {
    azer::Application app;
    app.run();
    return 0;
}
```

## 代码约定

### 命名空间
- 所有代码位于 `azer` 命名空间下

### 智能指针
- `scope<T>`: `std::unique_ptr<T>` 的别名，用于独占所有权
- `ref<T>`: `std::shared_ptr<T>` 的别名，用于共享所有权

### 预编译头
- 所有 `.cpp` 文件应在首行包含 `#include "azpch.h"`

## 当前状态

🚧 **开发中** - 这是一个学习项目，部分功能可能尚未完成。

### 已完成
- [x] 基础项目架构
- [x] Vulkan 渲染上下文框架
- [x] 窗口创建和管理
- [x] 多后端抽象层

### 计划中
- [ ] Vulkan 实例和设备初始化
- [ ] 交换链管理
- [ ] 渲染管线创建
- [ ] 资源管理
- [ ] OpenGL 后端实现
- [ ] Direct3D 12 后端实现

## 许可证

本项目用于学习目的。

## 参考资料

- [Vulkan 官方文档](https://vulkan.lunarg.com/)
- [vulkan.hpp GitHub](https://github.com/KhronosGroup/Vulkan-Hpp)
- [GLFW 文档](https://www.glfw.org/docs/latest/)
- [Sascha Willems Vulkan 示例](https://github.com/SaschaWillems/Vulkan)
