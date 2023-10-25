#include<iostream>
using namespace std;

class Node{
        public : 
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};


Node* createTree(Node* root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    root = new Node(data);

    if (data==-1)
    {
        return NULL;
    }

     cout<<"Enter data for inserting in left : ";
     root->left =  createTree(root->left);
     cout<<"Enter data for inserting in right : ";
     root->right = createTree(root->right);
     return root;   
}

void inorder(Node*root){
    if (root==NULL)
    {
       return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node * root = NULL;
        
    root = createTree(root);



    cout<<"Inorder traversal is : ";
    inorder(root);
    return 0;
}