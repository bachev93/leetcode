set(EASY_SOURCES
    balanced_binary_tree.cpp
    best_time_buy_and_sell_stock.cpp
    binary_search.cpp
    contain_duplicates.cpp
    find_idx_first_substr.cpp
    first_bad_version.cpp
    first_unique_char.cpp
    fizz_buzz.cpp
    guess_number.cpp
    hamming_distance.cpp
    implement_strstr.cpp
    list_cycle.cpp
    longest_common_prefix.cpp
    majority_element.cpp
    merge_two_sorted_lists.cpp
    merge_sorted_arr.cpp
    missing_number.cpp
    move_zeroes.cpp
    my_sqrt.cpp
    number_of_1_bits.cpp
    pascal_triangle.cpp
    plus_one.cpp
    power_of_three.cpp
    remove_duplicates.cpp
    remove_element.cpp
    reverse_integer.cpp
    reverse_list.cpp
    reverse_string.cpp
    roman_to_int.cpp
    rotate_array.cpp
    rotate_image.cpp
    same_tree.cpp
    single_number.cpp
    symmetric_tree.cpp
    two_sum.cpp
    valid_anagram.cpp
    valid_palindrome.cpp
    valid_parentheses.cpp
)

foreach(source ${EASY_SOURCES})
    string(REPLACE ".cpp" "" target_name ${source})
    add_executable(${target_name} ${source})
endforeach()
