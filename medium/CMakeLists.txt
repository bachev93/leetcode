set (MEDIUM_SOURCES
    find_anagrams.cpp
    group_anagrams.cpp    
)

foreach(source ${MEDIUM_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
