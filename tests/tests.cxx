#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <bits/stdc++.h>
#include <boost/test/unit_test.hpp>
#include "../utils/ProcessFiles.hpp"

using namespace std;

BOOST_AUTO_TEST_CASE(process_files_constructor_test){
    string file_name="test.csv";
    ProcessFiles test(file_name);
    BOOST_CHECK_EQUAL(test.get_file_name(),file_name);
}
BOOST_AUTO_TEST_CASE(process_files_sorted_test){
    const string date1="2018-12-10";
    const vector<string>result1{"eDAiRm6sjPO3dqE9","QDxJQwaGYNNPAgGX"};
    string file_name="test.csv";
    ProcessFiles test(file_name);
    vector<string>output=test.get_most_active(date1);
    BOOST_CHECK_EQUAL_COLLECTIONS(output.begin(),output.end(),result1.begin(),result1.end());

    const string date2="2018-12-09";
    const vector<string>result2{"AtY0laUfhglK3lC7"};
    vector<string>output2=test.get_most_active(date2);
    BOOST_CHECK_EQUAL_COLLECTIONS(output2.begin(),output2.end(),result2.begin(),result2.end());
}
BOOST_AUTO_TEST_CASE(test_throw_behavior){
    BOOST_CHECK_THROW(ProcessFiles("test2.csv"),exception);
}