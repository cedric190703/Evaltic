#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string funName;
    Node* next;
};

class LinkedList {
private :
    Node* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {};
    int getSize() { return this->size; };
    void addElement(const string& functionName);
    string deleteFirstElement();
    Node* getFirstElement(const string& functionName);
};