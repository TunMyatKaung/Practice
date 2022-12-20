//
// Created by TunMyatKaung on 12/9/2022.
//
#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *next;
};

void printData(struct node *printNode);
void insertData(struct node *prevNode, int newData);
int searchingData(struct node *myNode, int searchData);
void initial(struct node **myNode, int newData);
int main(){

    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;

    one=(struct node *)malloc(sizeof(struct node));
    two=(struct node *)malloc(sizeof(struct node));
    three=(struct node *)malloc(sizeof(struct node));

    one->data=10;
    two->data=20;
    three->data=30;

    one->next=two;
    two->next=three;
    three->next=NULL;

    printData(one);

    printf("After insert data\n");
    insertData(one,15);
    printData(one);

    printf("After searching data\n");
    int result=searchingData(one,20);
    if(result==0){
        printf("*Data Found*\n");
    }else{
        printf("Not found!!\n");
    }

    printf("After insert initailNode\n");
    initial(&one,5);
    printData(one);

    return 0;
}

void printData(struct node *printNode){
    while(printNode != NULL){
        printf("Data : %d\n",printNode->data);
        printNode=printNode->next;
    }
}

void insertData(struct node *prevNode, int newData){
    if(prevNode==NULL){
        return -1;
    }
    struct node *insertNode=(struct node *)malloc(sizeof(struct node));
    insertNode->data=newData;
    insertNode->next=prevNode->next;
    prevNode->next=insertNode;

}

int searchingData(struct node *myNode, int searchData){
    if(myNode == NULL){
        printf("Node is NULL:\n");
        return -1;
    }
    while(myNode!=NULL){
        if(searchData==myNode->data){
            return 0;
        }else{
            myNode=myNode->next;
        }
    }
}

void initial(struct node **myNode, int newData){
    struct node *initialNode=(struct node*)malloc(sizeof(struct node));
    initialNode->data=newData;
    initialNode->next=(*myNode);
    (*myNode)=initialNode;
}
