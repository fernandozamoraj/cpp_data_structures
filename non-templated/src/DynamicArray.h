#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef int DATATYPE;

class DynamicArray {
private:
    DATATYPE* data;
    int capacity;

public:
    DynamicArray(int initialSize);
    DynamicArray(DATATYPE initialArray[], int initialSize = 10);
    ~DynamicArray();
    int size() const;
    void resize(int newSize);
    DATATYPE& operator[](int index);
};

#endif