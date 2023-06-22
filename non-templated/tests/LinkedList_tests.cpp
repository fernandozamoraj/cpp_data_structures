#include<iostream>
#include <string>
#include "../src/LinkedList.h"

using std::cout;
using std::endl;
using std::string;

//To compile and run
//$ g++ LinkedList_tests.cpp ../src/LinkedList.cpp -o lltest.exe
//$ ./lltest.exe

void TestScaffold(bool passes, string testName){
    if(passes)
        cout << "PASSED Test: " << testName << endl;
    else
        cout << "FAILED Test: " << testName << endl;
}

void TestScaffold(bool passes, int actual, int expected, string testName){
    if(passes)
        cout << "PASSED Test: " << testName << endl;
    else{
        cout << "FAILED Test: " << testName << endl;
        cout << "   expected: " << expected << endl;
        cout << "     actual: " << actual << endl;
    }
}

void IsEmptyTests(){
    LinkedList list;
    bool sizeIsZero = list.size() == 0;
    bool isEmpty = list.isEmpty();

    TestScaffold(sizeIsZero, "List.size() == 0");
    TestScaffold(isEmpty, "List.isEmpty() == true");

    list.pushBack(10);
    TestScaffold(list.isEmpty() == false, "List should not be empty");
    TestScaffold(list.size() == 1, "List.size() == 1");   
}

void PushFront(){
    LinkedList list;
    DATATYPE val = 10;
    list.pushFront(val);
    
    TestScaffold(list.getFront() == val, val, list.getFront(), "1 PushFront: List.getFront()");
    TestScaffold(list.getBack() == val, val, list.getBack(), "2 PushFront: list.GetBack()");

    list.pushFront(20);
    TestScaffold(list.getFront() == 20, 20, list.getFront(), "3 PushFront: List.getFront()");
    TestScaffold(list.getBack() == 10, 10, list.getBack(), "4 PushFront: List.getBack()");   
}

void PushBack(){
    LinkedList list;
    DATATYPE val = 10;
    list.pushBack(val);
    
    TestScaffold(list.getFront() == val, val, list.getFront(), "1 PushBack: List.getFront()");
    TestScaffold(list.getBack() == val, val, list.getBack(), "2 PushBack: list.GetBack()");

    list.pushBack(20);
    TestScaffold(list.getFront() == val, val, list.getFront(), "3 PushBack: List.getFront()");
    TestScaffold(list.getBack() == 20, val, list.getBack(), "4 PushBack: List.getBack()");   
}

void DeleteFront(){
    LinkedList list;
    list.pushBack(10);
    list.deleteFront();

    TestScaffold(list.size() == 0, "1 DeleteFront with 1 element");

    list.pushBack(20);
    list.pushBack(30);
    list.deleteFront();
    TestScaffold(list.size() == 1, "2 DeleteFront list.size() == 1");
    TestScaffold(list.getFront()==30, "3 DeleteFront getFront with 2 elements");
    TestScaffold(list.getBack() == 30, "4 DeleteFront getBack with 2 elements");

    list.deleteFront();
    TestScaffold(list.size() == 0, "5 DeleteFront returns back to 0");
}


void DeleteBack(){
    LinkedList list;
    list.pushBack(10);
    list.deleteBack();

    TestScaffold(list.size() == 0, "1 DeleteBack with 1 element");

    list.pushBack(20);
    list.pushBack(30);
    list.deleteBack();
    TestScaffold(list.size() == 1, "2 DeleteBack list.size() == 1");
    TestScaffold(list.getFront()== 20, "3 DeleteBack getFront with 1 elements");
    TestScaffold(list.getBack() == 20, "4 DeleteBack getBack with 1 elements");

    list.deleteBack();
    TestScaffold(list.size() == 0, "5 DeleteBack returns back to 0");
}

void GetNodeByData(){
    LinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    TestScaffold(list.getNodeByData(10)->data == 10, "1 GetNodeByData");
    TestScaffold(list.getNodeByData(20)->data == 20, "2 GetNodeByData");
    TestScaffold(list.getNodeByData(30)->data == 30,  "3 GetNodeByData");
    TestScaffold(list.getNodeByData(0) == nullptr, "4 GetNodeByData");
}

int main(int argc, char* argv[]){

    IsEmptyTests();
    PushFront();
    PushBack();
    DeleteFront();
    DeleteBack();
    GetNodeByData();

    //some additional tests are necessary to test exceptions

    return 0;
}

/*
To compile and run these tests
.../tests$ g++ LinkedList_tests.cpp ../src/LinkedList.cpp -o lltest.exe
.../tests$ ./lltest.exe
PASSED Test: List.size() == 0
PASSED Test: List.isEmpty() == true
PASSED Test: List should not be empty
PASSED Test: List.size() == 1
PASSED Test: 1 PushFront: List.getFront()
PASSED Test: 2 PushFront: list.GetBack()
PASSED Test: 3 PushFront: List.getFront()
PASSED Test: 4 PushFront: List.getBack()
PASSED Test: 1 PushBack: List.getFront()
PASSED Test: 2 PushBack: list.GetBack()
PASSED Test: 3 PushBack: List.getFront()
PASSED Test: 4 PushBack: List.getBack()
PASSED Test: 1 DeleteFront with 1 element
PASSED Test: 2 DeleteFront list.size() == 1
PASSED Test: 3 DeleteFront getFront with 2 elements
PASSED Test: 4 DeleteFront getBack with 2 elements
PASSED Test: 5 DeleteFront returns back to 0
PASSED Test: 1 DeleteBack with 1 element
PASSED Test: 2 DeleteBack list.size() == 1
PASSED Test: 3 DeleteBack getFront with 1 elements
PASSED Test: 4 DeleteBack getBack with 1 elements
PASSED Test: 5 DeleteBack returns back to 0
PASSED Test: 1 GetNodeByData
PASSED Test: 2 GetNodeByData
PASSED Test: 3 GetNodeByData
PASSED Test: 4 GetNodeByData
fernandozamoraj@NANDO5530:/mnt/c/dev/cpp_data_structures/non-templated/tests$
*/