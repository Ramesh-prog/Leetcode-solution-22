// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s1, string s2) 
    { 
    // Your code goes here
        int m=s1.size();
        int n=s2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return m-dp[m][n] + n-dp[m][n];
    } 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends