#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
public:
    virtual void append(T value) = 0;
    virtual T& at(int index) = 0;
    virtual T at(int index) const = 0;
    virtual T& operator[](int index) = 0;

    virtual T operator[](int index) const = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(T value) = 0;
    virtual void appendList(const List<T>& other) = 0;
    virtual int find(T value) const = 0;
    virtual bool contains(T value) const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual void sort(bool asc) = 0;
    virtual void reverse() = 0;
    virtual ~List() {}
};

#endif /* LIST_H */
