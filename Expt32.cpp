#include<iostream>
using namespace std;

class queue{
        public : 
      int data;
      queue* next;

  
      queue(int x){
        data  = x;
        next = NULL;
      }
};

queue * f=NULL, *r=NULL;

void enqueue(int x){
    

  queue * newNode = new  queue(x);
      if (f==NULL && r==NULL)
      {
          f = newNode;
          r = newNode;
      }

      else {
        r->next = newNode;
        r = newNode;
      }
      
}

void dequeue(){
    if (f==NULL && r==NULL)
    {
       cout<<"Queue is empty. Cannot pop.";
    }
    else {

        cout<<"Popped element : "<<f->data<<endl;
        queue*temp = f;
        f = f->next;
        delete temp;

    }
}

void display(){
    queue*temp = f;
    if (temp==NULL)
    {
       cout<<"Queue is empty"<<endl;
    }
    
   else { cout<<"Elements of the queue are : ";
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
   }
    
}

int main(){
    enqueue(21);
     enqueue(1);
      enqueue(2);
       enqueue(3);
        enqueue(432);
         enqueue(341);
         display();

         dequeue();
         dequeue();

         display();
     
}