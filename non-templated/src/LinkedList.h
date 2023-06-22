#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

/*************************
 *  Designer: Fernando Zamora assisted by ChatGPT (chat.openai.com)
 *            
 *  This linked list is intended to function as a linked list and not like a list
 *  A list typically hides implementation details. For example the C++ sdt::vector
 *  can be handled similar to an array but it can also grow like a list.  The implementation
 *  details of the vector are hiddend intentionally for a better list interface.
 *  Since this is a linked list I want it to look like a linked list and provide an
 *  interface that allows it to be handled like a linked list.
 *  That is why in some cases it returns the entire node as opposed to just the data.
 * 
 *  This list can be further enhanced with popBack and popFront methods
****************************/

typedef int DATATYPE;

struct Node{
    DATATYPE data;
    Node *next;
    Node(DATATYPE data);
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int _size;

public:
    LinkedList();

    bool isEmpty() const;
    int size();
    DATATYPE getFront() const;
    DATATYPE getBack() const;
    void pushFront(DATATYPE value);
    void pushBack(DATATYPE value);
    void deleteFront();
    void deleteBack();
    Node* getNodeByIndex(int index) const;
    Node* getNodeByData(DATATYPE value) const;
    void insertNode(Node* existingNode, DATATYPE value);
};

#endif  // LINKEDLIST_H