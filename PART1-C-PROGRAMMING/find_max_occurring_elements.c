/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                /////////////////
// Write a C program to find out most frequently occurring number from a given set of    //
// possitive numbers ( value ranging from 1 to 100)                                      // 
// @author: Mohitesh Ch Agarwal                                                          //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                   //
///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

int count(int n, int arr[n], int element){
    int c = 0,i;
    for(i=0;i<n;i++)
        if(arr[i]==element)
            c++;
    return c;
}

int inResult(int n,int arr[n], int element){
    int i;
    for(i=0;i<=n;i++)
        if(arr[i]==element)
            return 0;
    return 1;
}

void count_freq_max(int n, int arr[n]){
    int max_freq = INT_MIN;
    int max_ele[100000],top=-1;
    int max_ele_freq[100000];
    int i;
    for(i=0;i<n;i++){
        int c = count(n,arr,arr[i]);
        if(max_freq<c){
            max_freq = c;
            top = -1;
            max_ele[++top] = arr[i];
            max_ele_freq[top] = c;
        }
        else if((max_freq==c) && inResult(top,max_ele,arr[i])){
            max_ele[++top] = arr[i];
            max_ele_freq[top] = c;
        }
    }

    // Displaying the max_frequenly occurring elements //
    for(i=0;i<=top;i++)
        printf("element-->%d occurs %d times\n",max_ele[i],max_ele_freq[i]);
}

int main(){
    // Taking set of elements input from user //
    int arr[100000],n;
    printf("Enter the number of elements of arr(array): ");
    scanf("%d",&n);
    printf("Enter the elements of array: ");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Displaying the result //
    count_freq_max(n,arr);

    return 0;
}