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



void insertAtBeginnig(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void deleteAtBeginnig(Node *&head){
    Node * temp = head; 
    head = head->next;
    delete temp;
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

    insertAtBeginnig(head, 23);
    insertAtBeginnig(head, 153);
    insertAtBeginnig(head, 155);
    insertAtBeginnig(head, 1);

    print(head);
    cout<<"Deleting at beginning : \n";
    deleteAtBeginnig(head);

    print(head);

    

   

    

   

    cout<<"head data : "<<head->data<<endl;
    cout<<"tail data : "<<tail->data<<endl;
}