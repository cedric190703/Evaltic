#include "LinkedList.h"

void LinkedList::addElement(const string& functionName) {
    Node* node = new Node;
    node->funName = functionName;
    node->next = head;
    head = node;
    size++;
}

string LinkedList::deleteFirstElement() {
    Node* tmp = head;
    string funName = tmp->funName;
    head = head->next;
    delete tmp;
    size--;
    return funName;
}

Node* LinkedList::getFirstElement(const string& functionName) {
    Node* curr = head;
    while(curr != nullptr) {
        if(curr->funName == functionName) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}
