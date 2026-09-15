cmake_minimum_required(VERSION 4.0)

project(DataStructure
        VERSION 0.1.0
        DESCRIPTION "手写数据结构与算法实现（C11）"
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "构建类型" FORCE)
endif()

# 所有可执行文件统一输出到 build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_compile_options(-Wall -Wextra)

# ============================================================
# 基础库 ds：编译 bases/ 下的全部实现，头文件目录对外公开
# ============================================================
file(GLOB DS_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/bases/*.c")

if(NOT DS_SOURCES)
    message(FATAL_ERROR "bases/ 目录下未找到任何 .c 源文件")
endif()

add_library(ds STATIC ${DS_SOURCES})
add_library(ds::ds ALIAS ds)

target_include_directories(ds
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/bases/include")

# ============================================================
# 演示入口 main.c
# ============================================================
add_executable(demo main.c)
target_link_libraries(demo PRIVATE ds::ds)
set_target_properties(demo PROPERTIES OUTPUT_NAME "main")

# ============================================================
# 每章应用：apps/chXX/<名称>.c
# ============================================================
add_subdirectory(apps)

# ============================================================
# 单元测试：tests/test_<模块>.c
# ============================================================
enable_testing()
add_subdirectory(tests)
