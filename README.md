# HeliosRender

Standalone DirectX 12 rendering engine library featuring both DXR ray tracing (BLAS/TLAS acceleration structures, shadow rays, point lighting) and D3D12 rasterization, decoupled from Qt and application shells.

## Project Type

- Visual Studio C++20 Static Library (`HeliosRender.lib`)
- Dependencies bundled in `include/` and `dlls/`:
  - DirectX 12 Agility / D3DX12 headers (`include/directx`)
  - DirectX Shader Compiler (`include/DXCompiler`, `dlls/dxcompiler.dll`, `dlls/dxil.dll`)
  - RapidJSON (`include/rapidjson`) for `.crtscene` parsing

## Building

Open `HeliosRender.sln` in Visual Studio or build via MSBuild:

```powershell
msbuild HeliosRender.sln /t:Rebuild /p:Configuration=Debug /p:Platform=x64
msbuild HeliosRender.sln /t:Rebuild /p:Configuration=Release /p:Platform=x64
```

Outputs are written to `x64/Debug/` or `x64/Release/`, including `HeliosRender.lib`, `dxcompiler.dll`, `dxil.dll`, and `ray_tracing_shader.hlsl`.

## Integrating into an Application

1. Add `D:\repos\HeliosRender`, `D:\repos\HeliosRender\include\directx`, `D:\repos\HeliosRender\include\DXCompiler\inc`, and `D:\repos\HeliosRender\include\rapidjson` to your consumer project's **Additional Include Directories** (or reference `HeliosRender.vcxproj` directly).
2. Link `HeliosRender.lib`, `d3d12.lib`, `dxgi.lib`, and `dxcompiler.lib`.
3. Ensure `dxcompiler.dll`, `dxil.dll`, and `ray_tracing_shader.hlsl` are present in the application's working/output directory (or call `DXRenderer::setRayTracingShaderPath(...)`).
4. Initialize and render using a native Win32 `HWND`:

```cpp
#include "HeliosRender.h"

DXRenderer renderer;
renderer.prepareForRendering(hwnd, width, height, true); // true = DXR ray tracing, false = rasterization

Scene scene;
auto camera = std::make_unique<CameraSceneObject>();
CameraSceneObject* camPtr = camera.get();
scene.addSceneObjects({ camera.release() });
SceneLoader::loadScene("scene.crtscene", &scene);

renderer.updateSceneVerticesVB(&scene);
const auto bg = scene.getBackgroundColor();
renderer.setBackgroundColor(bg.x, bg.y, bg.z, 1.0f);
renderer.updateSceneLights(&scene);
renderer.updateCameraBuffer(camPtr->getCameraBuffer());

FrameData frameData{};
renderer.renderFrame(frameData);
```
