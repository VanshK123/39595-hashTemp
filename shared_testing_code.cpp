#include <fstream>
#include <string>
#include <iostream>

#include "shared_testing_code.h"

/**
 * The following strings are for parsing trace files to determine how many points
 * each operation in the trace file is worth
 */

/** The string in the trace file that determines how many points basic tests are worth */
std::string basic_test_str("basic_tests");

/** The string in the trace file that determines how many points the copy constructor is worth */
std::string copy_constructor_str("copy_constructor");

/** The string in the trace file that determines how many points the = operator is worth */
std::string assignment_operator_str("=_operator");

/** The string in the trace file that determines how many points the self = test is worth */
std::string self_assignment_str("self_assignment");

/** The string in the trace file that determines how many points the basic iterator is worth */
std::string basic_iterator_str("basic_iterator");

/**
 * The string in the trace file that determines how many points the iterator for a copy
 * constructed list is worth
 */
std::string copy_iterator_str("copy_iterator");

/**
 * The string in the trace file that determines how many points the iterator for a =
 * constructed list is worth
 */
std::string assignment_iterator_str("=_iterator");

/**
 * The string in the trace file that determines how many points the get bucket sizes
 * function is worth
 */
std::string get_bucket_sizes("get_bucket_sizes");

/**
 * The string in the trace file that determines how many points the get all keys
 * function is worth
 */
std::string get_all_keys_str("get_all_keys");

/**
 * The string in the trace file that determines how many points the get all keys in
 * sorted order is worth
 */
std::string get_all_keys_sorted_str("get_all_keys");

test_results::test_results()
{
    basic_tests = {false, 0};
    basic_iterator = {false, 0};
    get_bucket_sizes = {false, 0};
    get_all_keys = {false, 0};
    get_all_keys_sorted_str = {false, 0};
}

test_results parse_trace_file_points(std::ifstream &trace_file)
{
    test_results results;
    std::string current_line;
    std::string operation;
    std::string operation_args;
    size_t delimeter_pos;
    size_t idx = 1;
    std::string delimeter = ":";

    while (getline(trace_file, current_line))
    {

        delimeter_pos = current_line.find(delimeter);

        if (delimeter_pos == std::string::npos)
        {
            std::cout << "Error on line " << idx << ", expected delimeter " << delimeter
                      << " in current line but didn't find it" << std::endl;
        }

        operation = current_line.substr(0, delimeter_pos);
        operation_args = current_line.substr(delimeter_pos + 1, std::string::npos);

        /** Assign point values to each test */
        if (operation == basic_test_str)
        {
            results.basic_tests.second = stoi(operation_args);
        }
        else if (operation == copy_constructor_str)
        {
            results.copy_constructor.second = stoi(operation_args);
        }
        else if (operation == assignment_operator_str)
        {
            results.assignment_operator.second = stoi(operation_args);
        }
        else if (operation == self_assignment_str)
        {
            results.self_assignment_operator.second = stoi(operation_args);
        }
        else if (operation == basic_iterator_str)
        {
            results.basic_iterator.second = stoi(operation_args);
        }
        else if (operation == copy_iterator_str)
        {
            results.copy_iterator.second = stoi(operation_args);
        }
        else if (operation == assignment_iterator_str)
        {
            results.assignment_iterator.second = stoi(operation_args);
        }
        else if (operation == get_bucket_sizes)
        {
            results.get_bucket_sizes.second = stoi(operation_args);
        }
        else if (operation == get_all_keys_str)
        {
            results.get_all_keys.second = stoi(operation_args);
        }
        else if (operation == get_all_keys_sorted_str)
        {
            results.get_all_sorted_keys.second = stoi(operation_args);
        }
        /** We've reached the end of the scores so we can return the scores to the caller */
        else
        {
            return results;
        }
    }

    return results;
}

void write_test_results_to_file(test_results results, std::ofstream &grading_file)
{
    size_t total_score = 0;

    if (results.basic_tests.first)
    {
        total_score += results.basic_tests.second;
    }

    if (results.copy_constructor.first)
    {
        total_score += results.copy_constructor.second;
    }

    if (results.assignment_operator.first)
    {
        total_score += results.assignment_operator.second;
    }

    if (results.self_assignment_operator.first)
    {
        total_score += results.self_assignment_operator.second;
    }

    if (results.basic_iterator.first)
    {
        total_score += results.basic_iterator.second;
    }

    if (results.copy_iterator.first)
    {
        total_score += results.copy_iterator.second;
    }

    if (results.assignment_iterator.first)
    {
        total_score += results.assignment_operator.second;
    }

    grading_file << "score: " << total_score << std::endl;
}