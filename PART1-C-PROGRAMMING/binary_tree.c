/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                ////////////////////////////////////////////////////
// Define a C structure to declare a node of a binary tree (containing integer values)                                      //
// Write a recursive function for post-order traversal of the tree.                                                         //
// @author: Mohitesh Ch Agarwal                                                                                             //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert_data(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;    // returning new node
}

/* MAIN LOGIC->post-order traversal */
void post_order(struct Node* root){
    if(!root)
        return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

int main(){
    struct Node* root = insert_data(20);
    root->left = insert_data(10);
    root->right = insert_data(15);
    root->left->left = insert_data(22);
    root->left->right = insert_data(24);
    root->right->left = insert_data(26);
    root->right->right = insert_data(27);

    post_order(root);   //post-order traversal

    return 0;
}