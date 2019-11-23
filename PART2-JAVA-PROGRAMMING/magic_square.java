import java.util.Scanner;
import java.io.*;

class MagicSquare {
    static int sum(int arr[]) {
        int total = 0;
        for (int i = 0; i < 3; i++)
            total += arr[i];
        return total;
    }

    static boolean checkMagicSquare(int arr[][]) {
        int sumOfRow[] = new int[3];
        int sumOfColumn[] = new int[3];
        int sumOfRightDiagonal = 0;
        int sumOfLeftDiagonal = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sumOfRow[i] += arr[i][j];
                sumOfColumn[i] += arr[j][i];
                if (i == j)
                    sumOfLeftDiagonal += arr[i][j];
                if (i == (2 - j))
                    sumOfRightDiagonal += arr[i][j];
            }
        }
        int k = sumOfRow[0];
        for (int i = 0; i < 1; i++) {
            if (k != sumOfRow[i])
                return false;
            if (k != sumOfColumn[i])
                return false;
        }
        if (k != sumOfLeftDiagonal || k != sumOfRightDiagonal)
            return false;
        return true;
    }

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int arr[][] = new int[3][3];
        // Taking the input of the Square
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = sc.nextInt();
        // Checking the square is a magic square
        boolean flag = checkMagicSquare(arr);
        if (flag == true)
            System.out.println("It is a magic square!");
        else
            System.out.println("It is not a magic square!");
        sc.close();
    }
}