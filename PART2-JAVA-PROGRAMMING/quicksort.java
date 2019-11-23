////////// SE ASSIGNMENT ////////////
// @author: Mohitesh Ch Agarwal    //
// ALL RIGHTS RESERVED             //
/////////////////////////////////////

import java.util.Scanner;
import java.io.*;

class Quick_sort{
    int partition(int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
        int tmp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = tmp;
        return (i+1);
    }

    void sort(int arr[], int low, int high){
        if(low<high){
            int p = partition(arr, low, high);
            sort(arr, low, p-1);
            sort(arr, p+1, high);
        }
    }

    static void printArr(int arr[]){
        for(int i=0;i<20;i++)
            System.out.print(arr[i]+", ");
        System.out.println();
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[20];
        // Taking input of 20 integers to sort
        for(int i=0;i<20;i++)
            arr[i] = sc.nextInt();
        // Sorting the array
        Quick_sort ob1 = new Quick_sort();
        ob1.sort(arr,0,19);

        System.out.println("Sorted Array");
        printArr(arr);
    }
}