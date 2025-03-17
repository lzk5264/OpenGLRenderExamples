cmake_minimum_required(VERSION 3.10)
project(OpenGLRenderExamples)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
set(SOURCE_FILES
    src/main.cpp
    src/glad.c
    src/window.cpp
    src/renderer.cpp
    src/application.cpp
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# 添加头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加库文件路径
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 链接库文件
if(WIN32)
    target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
else()
    target_link_libraries(${PROJECT_NAME} glfw3 GL dl)
endif()

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)