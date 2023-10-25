#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        this->next = NULL;
    }
};



void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}


void deleteAtPosition(Node*&head,Node*&tail,int pos){
  
        if (pos < 1 || !head) {
            cout<<"Invalid position.";
            return; 
        }

        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            if (!current->next) {
                return;
            }
            current = current->next;
        }

        Node* temp = current->next;
        if (temp) {
            current->next = temp->next;
            delete temp;
        }
    }


void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;

    Node *tail = node1;

    print(head);

    insertAtHead(head, 15);

    print(head);

    insertAtEnd(tail, 19);

    print(head);
    deleteAtPosition(head,tail,2);
    print(head);
    

    cout<<"head data : "<<head->data<<endl;
    cout<<"tail data : "<<tail->data<<endl;
}