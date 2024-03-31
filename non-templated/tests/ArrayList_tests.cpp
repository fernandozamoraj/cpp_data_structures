#include <iostream>
#include <string>
#include "../src/ArrayList.hpp"
#include "test.hpp"

using std::cout;
using std::endl;
using std::string;

void test_append() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    test_equals(1, list.at(0), "append - index 0");
    test_equals(3, list.at(2), "append - index 2");
    test_equals(5, list.at(4), "append - index 4");
}

void test_insert() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.insert(0, 0);
    list.insert(1, 11);
    list.insert(5, 55);

    test_equals(0, list.at(0), "insert - at beginning");
    test_equals(11, list.at(1), "insert - at middle");
    test_equals(55, list.at(5), "insert - in end");
}

void test_remove() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.remove(1);
    list.remove(3);
    list.remove(5);

    test_equals(2, list.at(0), "remove - at beginning");
    test_equals(4, list.at(1), "remove - at end");
    test_equals(2, list.size(), "remove - at end size");
}



void test_clear() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.clear();

    test_equals(0, list.size(), "clear - size");
}

void test_reverse() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverse();

    test_equals(3, list.at(0), "reverse - index 0");
    test_equals(2, list.at(1), "reverse - index 1");
    test_equals(1, list.at(2), "reverse - index 2");
}

void test_array_operator() {
    ArrayList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    test_equals(1, list[0], "operator[] - index 0");
    test_equals(2, list[1], "operator[] - index 1");
    test_equals(3, list[2], "operator[] - index 2");

    list[1] = 4;
    test_equals(4, list[1], "operator[] - modified value");
}

// Add more test functions as needed

int main() {
    test_append();
    test_insert();
    test_remove();
    test_clear(); // Add the test for clear
    test_reverse(); // Add the test for reverse
    test_array_operator(); // Add the test for the array operator

    // Call other test functions here
    return 0;
}


