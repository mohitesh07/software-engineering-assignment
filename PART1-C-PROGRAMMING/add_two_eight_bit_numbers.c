/////////////////          SOFTWARE ENGINEERING ASSIGNMENT                /////////////////
// Write a C program to add two 8-bit binary numbers(input is a sequence of '0' and '1') //
// and output the result in both decimal and binary formats                              // 
// @author: Mohitesh Ch Agarwal                                                          //
// Copyright Mohitesh Ch Agarwal | All rights reserved                                   //
///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Converts binary to decimal */
int to_decimal(int num){
    int dec_num = 0;
    int i = 0;
    while(i<8){
        int d = num%10;
        num /= 10;
        dec_num += pow(2,i)*d; 
        i++;
    }
    return dec_num;
}

/* Converts decimal to binary */
int to_binary(int num){
    int bin_num = 0;
    int i = 0;
    while(i<8){
        int d = (num>>i)&1;
        bin_num += pow(10,i)*d;
        i++;
    }
    return bin_num;
}

/* finds the sum of two numbers */
int sum_of_numbers(int a,int b){
    return a+b;
}

int main(){
    int num1,num2;
    printf("Enter two binary numbers: ");
    scanf("%u",&num1);
    scanf("%u",&num2);

    ///// Finding thier sum
    int sum = sum_of_numbers(to_decimal(num1),to_decimal(num2));
    
    //// Displaying the result
    printf("%u + %u = %u or %u\n",num1,num2,to_binary(sum),sum);
    
    return 0;   // returns 0 to the operating system
}