#include "LinkedList.h"
#include <stdexcept>

Node::Node(DATATYPE value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), _size(0) {}

bool LinkedList::isEmpty() const {
    return _size == 0;
}

int LinkedList::size(){
    return _size;
}

DATATYPE LinkedList::getFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Linked list is empty.");
    }
    return head->data;
}

DATATYPE LinkedList::getBack() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Linked list is empty.");
    }
    return tail->data;
}

void LinkedList::pushFront(DATATYPE value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    _size++;
}

void LinkedList::pushBack(DATATYPE value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    _size++;
}

void LinkedList::deleteFront() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Linked list is empty.");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    _size--;
    if (isEmpty()) {
        tail = nullptr;
    }
}

void LinkedList::deleteBack() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Linked list is empty.");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    _size--;
}

Node* LinkedList::getNodeByIndex(int index) const {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Error: Invalid index.");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

Node* LinkedList::getNodeByData(DATATYPE value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::insertNode(Node* existingNode, DATATYPE value) {
    if (existingNode == nullptr) {
        throw std::invalid_argument("Error: Existing node cannot be null.");
    }
    Node* newNode = new Node(value);
    newNode->next = existingNode->next;
    existingNode->next = newNode;
    if (existingNode == tail) {
        tail = newNode;
    }
    _size++;
}

void LinkedList::insertAfter(Node* currentNode, DATATYPE value){
    Node* newNode = new Node(value);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    if (currentNode == head) {
        head = head;
    }
    if(newNode->next == nullptr)
        tail = newNode;
        
    _size++;
}