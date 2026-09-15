# 约定：apps/chXX/<名称>.c
# 每个 .c 编译为一个独立可执行程序，链接 ds 库。
# 目标名由相对路径推导，例如 apps/ch08/parenthesis.c -> ch08_parenthesis

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/ch*/*.c")

foreach(app_src IN LISTS APP_SOURCES)
    file(RELATIVE_PATH app_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${app_src}")
    string(REPLACE "/" "_" app_name "${app_rel}")
    string(REGEX REPLACE "\\.[^.]+$" "" app_name "${app_name}")

    add_executable("${app_name}" "${app_src}")
    target_link_libraries("${app_name}" PRIVATE ds::ds)
endforeach()
