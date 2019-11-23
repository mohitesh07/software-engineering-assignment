////////// SE ASSIGNMENT ////////////
// @author: Mohitesh Ch Agarwal    //
// ALL RIGHTS RESERVED             //
/////////////////////////////////////

import java.util.*;
import java.lang.*;
import java.io.*;
class Trip
{
    public static final int MOD = 1000000007;
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		tk = new StringTokenizer(br.readLine());
		int n=Integer.parseInt(tk.nextToken()),m=Integer.parseInt(tk.nextToken());
		int[] location = new int[n];
		for(int i=0;i<n;i++){
		    location[i] = Integer.parseInt(br.readLine());
		}
		int[] dp = new int[n];
		int[] arr = new int[n];
		long counter=0;
        int k=0,j=0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
			while (location[i] - location[j] > m) {
				counter -= dp[j];
				j++;
			}
			arr[i] = arr[j] + 1;
			while (arr[k] == arr[j]){
    			counter += dp[k];
    			k++;    
			}
			dp[i] += counter % MOD;
		}
		System.out.println((arr[n-1]-1) + " " + dp[n-1]);
	}
}