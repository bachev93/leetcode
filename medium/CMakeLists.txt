set (MEDIUM_SOURCES
    add_two_numbers.cpp
    find_all_anagrams_in_string.cpp
    find_anagrams.cpp
    find_min_in_rotated_sorted_array.cpp
    four_sum.cpp
    group_anagrams.cpp
    merge_intervals.cpp
    number_of_islands.cpp
    search_2d_matrix.cpp
    search_in_rotated_sorted_array.cpp
    top_k_frequent_elements.cpp
    top_k_frequent_words.cpp
)

foreach(source ${MEDIUM_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
