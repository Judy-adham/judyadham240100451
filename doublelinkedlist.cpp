#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;



void insertFirst(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
        head->prev = newNode;
    else
        tail = newNode; 

    head = newNode;
}


void insertEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr)
        tail->next = newNode;
    else
        head = newNode; 

    tail = newNode;
}

void displayForward() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void displayBackward() {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

