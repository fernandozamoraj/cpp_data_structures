#include <stdexcept>
#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialSize) {
    capacity = initialSize;
    data = new DATATYPE[capacity];
}

DynamicArray::DynamicArray(DATATYPE initialArray[], int initialSize = 10) {
    capacity = initialSize;
    data = new DATATYPE[capacity];

    for(int i=0;i<initialSize;i++){
        data[i] = initialArray[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

int DynamicArray::size() const {
    return capacity;
}

void DynamicArray::resize(int newSize) {
    DATATYPE *newData = new DATATYPE[newSize];
    for(int i=0; i<size();i++)
        newData[i] = data[i];
    capacity = newSize;
    delete [] data;
    data = newData;
}

DATATYPE& DynamicArray::operator[](int index) {
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}