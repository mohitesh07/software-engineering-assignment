////////// SE ASSIGNMENT ////////////
// @author: Mohitesh Ch Agarwal    //
// ALL RIGHTS RESERVED             //
/////////////////////////////////////

import java.io.*;
import java.util.Scanner;

class Factorial{
    long fact(int n){
        if(n==0)
            return 1;
        return n*fact(n-1);
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a whole number less than equal to 20: ");
        int n = sc.nextInt();
        // Displaying the factorial
        Factorial ob1 = new Factorial();
        System.out.format("The factorial of %d is %d",n,ob1.fact(n));
    }
}