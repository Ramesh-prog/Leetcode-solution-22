// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{

  public:
	int minDifference(int arr[], int n)  
	{ 
	    // Your code goes here
	    int i,j,sum=0,mn=INT_MAX;
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        bool t[n+1][sum+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(i==0)
                {
                    t[i][j]=0;
                }
                if(j==0)
                {
                    t[i][j]=1;
                }
            }
        }
    
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                if(arr[i-1]>j)
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
    
        vector<int> v;
    
        for(j=0;j<=sum/2;j++)
        {
            if(t[n][j]==1)
            {
                v.push_back(j);
            }
        }
    
        for(i=0;i<v.size();i++)
        {
            mn = min(mn,sum-2*v[i]);
        }
        return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends