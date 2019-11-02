/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                ////////////////////////////////////////////////////
// It is needed to maintain the records of batsmen (name, runs scored and country) in a descending order of                 //
//  the runs scored by them. Write a C program which accepts the information about batsmen from the user                    //
// insert the same in a linkedlist and finally print the list                                                               //
// @author: Mohitesh Ch Agarwal                                                                                             //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
 
struct node{                      // batsmen node 
    char* name;
    int runs_scored;
    char* country;
    struct node* next;
};

struct node* new_node(char* name, int runs_scored, char* country){
    struct node* Node = (struct node*)malloc(sizeof(struct node)); //allocating new node
    Node->name = name;                                         //allocate data
    Node->runs_scored = runs_scored;
    Node->country = country;

    return Node;
}

void print_list(struct node* head){
    struct node* tmp = head;
    while(tmp!=NULL){
        printf("Name:%s, Runs_scored:%d, Country_of_origin:%s\n", tmp->name, tmp->runs_scored, tmp->country);
        tmp = tmp->next;
    }
}

/* MAIN LOGIC --> SORTED INSERT */
struct node* sorted_insert(struct node* head_ref, struct node* newNode){
    struct node* current;
    if(head_ref==NULL || (head_ref->runs_scored <= newNode->runs_scored)){
        newNode->next = head_ref;
        head_ref = newNode;
    }
    else{
        current = head_ref;
        while(current->next!=NULL && current->next->runs_scored>newNode->runs_scored)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
    return head_ref;
}

int main(){
    struct node* head = NULL;
    struct node* newNode = new_node("Sachin Tendulkar",25000,"India");
    head = sorted_insert(head, newNode);

    newNode = new_node("AB Deviliers",20000,"South Africa");
    head = sorted_insert(head, newNode);

    newNode = new_node("Yusuf Pathan",1000,"India");
    head = sorted_insert(head, newNode);

    newNode = new_node("Sehvag",23000,"India");
    head = sorted_insert(head, newNode);

    printf("The created linked list is :\n");
    print_list(head);

    return 0;   // returns SUCCESS to the Operating System
}