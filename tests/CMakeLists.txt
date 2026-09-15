# 约定：tests/test_<模块>.c
# 每个文件包含一个 main()，作为独立测试程序注册到 CTest。

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/test_*.c")

foreach(test_src IN LISTS TEST_SOURCES)
    get_filename_component(test_name "${test_src}" NAME_WE)

    add_executable("${test_name}" "${test_src}")
    target_link_libraries("${test_name}" PRIVATE ds::ds)

    add_test(NAME "${test_name}" COMMAND "${test_name}")
endforeach()
