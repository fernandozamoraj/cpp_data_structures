#include <iostream>
#include <string>
#include "../src/DynamicArray.h"

using std::cout;
using std::endl;
using std::string;

//To compile and run
//$ g++ arrays.cpp -o arrays.exe
//$ ./arrays.exe
/*  Sample Output
----------Ages-------------
19, 21, 33,

*/


void print(DynamicArray values, string name){

    cout << "----------" << name << "-------------" << endl;

    for(int i=0;i<values.size();i++){
        cout << values[i];

        //print the comma but not at the end of the line
        if(i < values.size()-1) cout << ", ";
    }

    cout << endl;
}

void receiveArray(DynamicArray ages){
    print(ages, "Ages");
}


int main(int argc, char* argv[]){

    DATATYPE a[] = {19,21,33};
    DynamicArray ages(a, 3);

    receiveArray(ages);

    return 0;
}