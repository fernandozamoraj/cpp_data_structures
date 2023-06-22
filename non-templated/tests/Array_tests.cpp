#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//To compile and run
//$ g++ arrays.cpp -o arrays.exe
//$ ./arrays.exe
/*  Sample Output
----------Ages-------------
19, 21, 33,
----------Names-------------
David, Mike, Anne,
----------Names after setting random name-------------
David, Xavier, Anne,
Printing 2D Array
-----------------------------------------
   1    2    3    4    5    6    7
-----------------------------------------
   1    2    3    4    5    6    7
   2    4    6    8   10   12   14
   3    6    9   12   15   18   21
   4    8   12   16   20   24   28
   5   10   15   20   25   30   35
   6   12   18   24   30   36   42
   7   14   21   28   35   42   49

*/

template <typename T>
void print(T values[], int count, string name){

    cout << "----------" << name << "-------------" << endl;

    for(int i=0;i<count;i++){
        cout << values[i];

        //print the comma but not at the end of the line
        if(i < count-1) cout << ", ";
    }

    cout << endl;
}

void receiveArray(int ages[], int count){
    print(ages, count, "Ages");
}

void receiveArray(string names[], int count){
    print(names, count, "Names");
}

void setRandomName(string names[], int count, int idx){
    names[idx] = "Xavier";
    print(names, count, "Names after setting random name");
}

void print2DArray(int** arr, int d1, int d2){
    cout << "Printing 2D Array" << endl;
    cout << "-----------------------------------------"<<endl;
    for(int i = 0; i < d1; i++){
        for(int j=0; j < d2; j++){
            
            //poorman's padding
            if(arr[i][j] < 1000) cout << " ";
            if(arr[i][j] < 100) cout << " ";
            if(arr[i][j] < 10) cout << " ";
            
            cout << arr[i][j];

            if(j < d2+1)
                cout << " ";    
        }
        cout << endl;
    }
    cout << endl;
}

int** createTimesTables(int highestNumber){

    //the arrays is an array of arrays of pointers
    int** timesTable = new int*[highestNumber];
    for (int i = 0; i < highestNumber; i++) {

        //allocate memory for each array in the first array
        timesTable[i] = new int[highestNumber];

        for (int j = 0; j < highestNumber; j++) {
            timesTable[i][j] = (i + 1) * (j + 1);
        }
    }

    return timesTable;
}

int main(int argc, char* argv[]){

    int ages[] = {19,21,33};
    string names[] = {"David", "Mike", "Anne"};

    receiveArray(ages, 3);
    receiveArray(names, 3);
    setRandomName(names, 3, 1);
    int** timesTable = createTimesTables(7);
    print2DArray(timesTable, 7, 7);
    
    //Always delete your dynamically allocated arrays
    //to avoid memory leaks
    delete [] timesTable;

    return 0;
}