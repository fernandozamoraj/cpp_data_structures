#ifndef TEST_HPP
#define TEST_HPP
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
bool check_equals(T expected, T actual){
    return expected == actual;
}

template<typename T>
bool test_equals(T expected, T actual, string testName){
    bool result = check_equals(expected, actual);

    if(result == true){
        cout << "Test " << testName << " passed" << endl;
    }
    else{
        cout << "Test " << testName << " failed!" << endl;
        cout << "    Expected: " << expected << endl;
        cout << "    But Was: " << actual << endl;
    }

    return result;
}


#endif