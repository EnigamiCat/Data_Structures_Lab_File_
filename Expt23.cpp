#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

     
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;  
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;  
        }
    }

     
    void display() {
        if (!head) {
            cout << "Circular Linked List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "Head" << endl;
    }
};

int main() {
    CircularLinkedList clist;

    clist.insert(1);
    clist.insert(2);
    clist.insert(3);
    clist.insert(4);

    cout << "Circular Linked List:" << endl;
    clist.display();

    return 0;
}
