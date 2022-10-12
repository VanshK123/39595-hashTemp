#ifndef __SHARED_TESTING_CODE_H
#define __SHARED_TESTING_CODE_H

#include <string>

/** Holds the results of each test and the associated point values */
struct test_results
{
    /** Flag and point values for passing basic tests */
    std::pair<bool, size_t> basic_tests;
    /** Flag and point values for passing copy constructor tests */
    std::pair<bool, size_t> copy_constructor;
    /** Flag and point values for passing assignment operator tests */
    std::pair<bool, size_t> assignment_operator;
    /** Flag and point values for passing self assignment tests */
    std::pair<bool, size_t> self_assignment_operator;
    /** Flag and point values for passing basic iterator tests */
    std::pair<bool, size_t> basic_iterator;
    /** Flag and point values for passing copy iterator tests */
    std::pair<bool, size_t> copy_iterator;
    /** Flag and point values for passing assignment iterator */
    std::pair<bool, size_t> assignment_iterator;
    /** Flag and point value for passing get bucket sizes */
    std::pair<bool, size_t> get_bucket_sizes;
    /** Flag and point value for passing get all keys */
    std::pair<bool, size_t> get_all_keys;
    /** Flag and point value for passing get all sorted keys */
    std::pair<bool, size_t> get_all_sorted_keys;
    
    /** 
     * Construct a test_results object with all tests initalized to false and with 
     * point values of 0
     */
    test_results();
};


test_results parse_trace_file_points(std::ifstream &trace_file);

void write_test_results_to_file(test_results results, std::ofstream& grading_file);

#endif