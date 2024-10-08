set (MEDIUM_SOURCES
    add_two_numbers.cpp
    best_time_buy_and_sell_stock_II.cpp
    container_most_water.cpp
    find_all_anagrams_in_string.cpp
    find_anagrams.cpp
    find_first_and_last_pos_elem_sorted_array.cpp
    find_min_in_rotated_sorted_array.cpp
    four_sum.cpp
    group_anagrams.cpp
    merge_intervals.cpp
    number_of_islands.cpp
    partition_labels.cpp
    remove_nth_element.cpp
    search_2d_matrix.cpp
    search_in_rotated_sorted_array.cpp
    three_sum_closet.cpp
    top_k_frequent_elements.cpp
    top_k_frequent_words.cpp
)

foreach(source ${MEDIUM_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
