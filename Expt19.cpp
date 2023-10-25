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





void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void deleteAtEnd(Node*&tail,Node*&head){
    
   if(head==NULL){
    cout<<"Linked List is empty.";

   }

   if (head->next==NULL)
   {
    delete head;
    head = NULL;
   }
   
   Node* temp = head;
   while (temp->next->next)
   {
    temp = temp->next;
   }
   delete temp->next;
   temp->next = NULL;
   tail = temp;

}


void search(Node*head,int d){
    Node* temp = head;
    while (temp)
    {
       if (temp->data == d)
       {
            cout<<"Element is found.\n";
            return;
       }
       temp = temp->next;
    }
    cout<<"Element not found.\n" ;
    return;  
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

    insertAtEnd(tail,20);
    insertAtEnd(tail,30);
    insertAtEnd(tail,40);
    insertAtEnd(tail,50);

    print(head);

    deleteAtEnd(tail,head);

    print(head);    

    int key;
    cout<<"Enter element to search : ";
    cin>>key;
    search(head,key);

   

   
}