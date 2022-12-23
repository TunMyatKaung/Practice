//
// Created by TunMyatKaung on 12/22/2022.
//
#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
public:
    int data;
    class Node *left;   //put NULL here might be error
    class Node *right;
};

class Node *creatNode(int key){
    class Node* newnode=(class Node*)malloc(sizeof(class Node));

    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

class Node *insertNode(class Node *passRoot, int key){

    if(passRoot == NULL){
        return creatNode(key);
    }
    if(key < passRoot->data){
        passRoot->left=insertNode(passRoot->left,key);
    }
    else{
        passRoot->right=insertNode(passRoot->right,key);
    }

    return passRoot;
}

void inorderTraversal(class Node *node){

    if(node != NULL){
        inorderTraversal(node->left);
        cout<<node->data<<endl;
        inorderTraversal(node->right);
    }
}

void finder(class Node *node,int key){

    if(node != NULL){
        finder(node->left,key);
            if(node->data == key){
                cout<<"We found "<<node->data;
            }
        finder(node->right,key);
    }
}

int main(){
    class Node* root=NULL;

    root=insertNode(root,5);
    root=insertNode(root,4);
    root=insertNode(root,3);
    root=insertNode(root,2);
    root=insertNode(root,1);
    root=insertNode(root,10);
    root=insertNode(root,9);
    root=insertNode(root,8);
    root=insertNode(root,7);
    root=insertNode(root,6);

    inorderTraversal(root);
    finder(root,10);

    return 0;
}
