/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                ////////////////////////////////////////////////////
// Write a C program to arrange integer in an array so that all negative integer preceed all positive integer               //
// @author: Mohitesh Ch Agarwal                                                                                             //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int queue[MAX_SIZE];
int top = -1;
int front = -1;

void display(int n){
    printf("The array is: ");
    int i;
    for(i=0;i<n;i++)
        printf("%d, ",arr[i]);
}

void negative_pos_preceed(int n){
    int i;
    int first = 1;
    for(i=0;i<n;i++){
        if(arr[i]<0 && top!=-1 && front!=top){
            int pos = queue[front];
            int tmp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = tmp;
            front++; 
        }
        if(arr[i]>=0){
            queue[++top] = i;
            if(first==1){
                front = 0;
                first = -1;
            }

        }
    }
}

int main(){
    /* Taking the array as input */
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    negative_pos_preceed(n);    // calling the function
    display(n);

    return 0;   // returning to the Operating System
}