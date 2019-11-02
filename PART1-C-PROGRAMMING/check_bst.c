/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                ////////////////////////////////////////////////////
// Write a C program which takes a binary tree as input and checks it is a binary search tree                               //
// @author: Mohitesh Ch Agarwal                                                                                             //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

int is_bst = 1;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void check_bst(struct node* root){
    if(!root)
        return;
    if(root->left)
        if(root->data<root->left->data){
            is_bst = -1;
            return;
        }
    if(root->right)
        if(root->data>root->right->data){
            is_bst =  -1;
            return;
        }
    check_bst(root->left);
    check_bst(root->right);
}

int main(){
    struct node* root = create_node(10);
    root->left = create_node(9);
    root->right = create_node(11);
    root->left->left = create_node(8);

    check_bst(root);

    if(is_bst==1)
        printf("It is a Binary-Search-Tree\n");
    else 
        printf("It is not a Binary Search Tree\n");

    return 0;   // returns 0 to the Operating System
}