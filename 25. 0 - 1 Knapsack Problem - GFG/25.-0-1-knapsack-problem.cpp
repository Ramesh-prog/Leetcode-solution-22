// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[],int val[],int **dp,int w,int n){
        if(n==0||w==0) return 0;
        
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        int a = INT_MIN;
        if(wt[n-1]<=w){
            a = val[n-1] + helper(wt,val,dp,w-wt[n-1],n-1);
        }
        int b = helper(wt,val,dp,w,n-1);
         return dp[n][w] = max(a,b);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int **dp = new int*[n+1];
       for(int i=0;i<=n;i++){
           dp[i] = new int[W+1];
           for(int j=0;j<=W;j++){
               dp[i][j] = -1;
           }
       }
       return helper(wt,val,dp,W,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends