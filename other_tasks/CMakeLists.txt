set(OTHER_TASKS_SOURCES
    base_der_err.cpp
    base_der_exc.cpp
    class_task.cpp
    const_issues.cpp
    point_map.cpp
    reverse_cstr.cpp
    split_words.cpp
    struct_test.cpp
    template_task.cpp
)

foreach(source ${OTHER_TASKS_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
