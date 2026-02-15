#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
 
void insertbeg(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertend(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(head==NULL){
        head = newnode;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

void del(){
    if(head==NULL){
        return;
    }else if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        node* temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void display(){
    node* temp = head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }

}

int main(){
    insertbeg(3);
    insertend(7);
    insertend(2);
    del();
    insertend(1);
    display();

}