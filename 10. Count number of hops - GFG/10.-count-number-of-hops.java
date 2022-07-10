// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG
{
    public static void main(String args[])
    {
        //taking input using Scanner class
        Scanner sc = new Scanner(System.in);
        
        //taking number of testcases
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            //taking number of steps in stair
            int n = sc.nextInt();
            
            //calling method countWays() of class Hops
            System.out.println(new Solution().countWays(n));
            
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution
{
    //Function to count the number of ways in which frog can reach the top.
    static int mod = 1000000007;
    static long ways(int n,long dp[])
    {
        if(n < 0)  return 0;
        else if( n == 0) return 1;
        else if(dp[n] != 0)  return dp[n];
        
        long res = 0;
        res += ways(n-1,dp) % mod;
        res += ways(n-2,dp) % mod;
        res += ways(n-3,dp) % mod;

        dp[n] = res%mod;
        return res%mod;
    }
    static long countWays(int n)
    {
       if(n == 0)
       return 0;
       long dp[] = new long[n+1];
       Arrays.fill(dp,0);
       return ways(n,dp);
    }
    
}

