get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(PROJECT_NAME jade_directx_examples_${PROJECT_ID})

add_executable(${PROJECT_NAME} main.cpp)

find_library(D3D11_LIBRARY d3d11.lib PATHS "$ENV{DXSDK_DIR}/Lib/x86" "C:/Program Files (x86)/Microsoft DirectX SDK/Lib/x86"     DOC "The directory where d3d11.lib resides")
find_library(D3DX11_LIBRARY d3dx11.lib PATHS "$ENV{DXSDK_DIR}/Lib/x86" "C:/Program Files (x86)/Microsoft DirectX SDK/Lib/x86"     DOC "The directory where d3dx11.lib resides")

target_link_libraries(TestProject "${D3D11_LIBRARY}" "D3DX11_LIBRARY")

target_link_libraries(${PROJECT_NAME} PRIVATE
        jade_common jade_directx
        d3d11.lib dxgi.lib dxguid.lib uuid.lib
        kernel32.lib user32.lib
        comdlg32.lib advapi32.lib shell32.lib
        ole32.lib oleaut32.lib
)
