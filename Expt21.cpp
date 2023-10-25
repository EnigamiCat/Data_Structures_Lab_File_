#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};


int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}


Node* findMergePoint(Node* list1, Node* list2) {
    int len1 = getLength(list1);
    int len2 = getLength(list2);

    Node* current1 = list1;
    Node* current2 = list2;

   
    while (len1 > len2) {
        current1 = current1->next;
        len1--;
    }

    while (len2 > len1) {
        current2 = current2->next;
        len2--;
    }

    
    while (current1 != current2) {
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1; 
}

int main() {
    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);

    LinkedList list2;
    list2.insertAtEnd(4);

   
    list2.head->next = list1.head->next;

    Node* mergePoint = findMergePoint(list1.head, list2.head);

    if (mergePoint) {
        cout << "Merge Point Data: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
