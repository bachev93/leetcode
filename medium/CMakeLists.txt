set (MEDIUM_SOURCES
    add_two_numbers.cpp
    find_all_anagrams_in_string.cpp
    find_anagrams.cpp
    group_anagrams.cpp
    search_2d_matrix.cpp
    top_k_frequent_elements.cpp
    top_k_frequent_words.cpp
)

foreach(source ${MEDIUM_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
