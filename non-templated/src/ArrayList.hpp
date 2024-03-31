#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <algorithm>
#include "list.h"

template<typename T>
class ArrayList : public List<T> {
private:
    T* data;
    int capacity;
    int currentSize;

public:
    ArrayList() : capacity(10), currentSize(0) {
        data = new T[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void append(T value) override {
        if (currentSize == capacity) {
            // Resize the array if it's full
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < currentSize; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[currentSize++] = value;
    }

    T& at(int index) override {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T at(int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    T& operator[](int index) {
        return at(index);
    }

    T operator[](int index) const{
        return at(index);
    }


    void insert(int index, T value) override {
        if (index < 0 || index > currentSize) {
            throw std::out_of_range("Index out of bounds");
        }

        if (currentSize == capacity) {
            // Resize the array if it's full
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < index; ++i) {
                newData[i] = data[i];
            }
            newData[index] = value;
            for (int i = index; i < currentSize; ++i) {
                newData[i + 1] = data[i];
            }
            delete[] data;
            data = newData;
        } else {
            for (int i = currentSize; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = value;
        }
        currentSize++;
    }

    void remove(T value) override {
        int index = -1;
        for (int i = 0; i < currentSize; ++i) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < currentSize - 1; ++i) {
                data[i] = data[i + 1];
            }
            currentSize--;
        }
    }

    T remoteAt(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }

        T removedValue = data[index];

        for (int i = index; i < currentSize - 1; ++i) {
            data[i] = data[i + 1];
        }

        currentSize--;

        return removedValue;
    }

    void appendList(const List<T>& other) override {
        for (int i = 0; i < other.size(); ++i) {
            append(other.at(i));
        }
    }


    int find(T value) const override {
        for (int i = 0; i < currentSize; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    bool contains(T value) const override {
        return find(value) != -1;
    }

    int size() const override {
        return currentSize;
    }

    void clear() override {
        delete [] data;
        data = new T[capacity];
        currentSize = 0;
    }

    void sort(bool asc) override {
        if (asc) {
            std::sort(data, data + currentSize);
        } else {
            std::sort(data, data + currentSize, std::greater<T>());
        }
    }

    void reverse() override {
        for (int i = 0; i < currentSize / 2; ++i) {
            std::swap(data[i], data[currentSize - i - 1]);
        }
    }
};

#endif



