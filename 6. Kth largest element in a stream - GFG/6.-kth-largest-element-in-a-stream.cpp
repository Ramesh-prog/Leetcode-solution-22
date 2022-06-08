// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
    	// your code here
    	int i=0;
        while(i < k-1)
        {
            cout<<-1<<" ";
            i++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);
        cout<<pq.top()<<" ";
        i++;
        
    	while(i < n)
    	{
    	    if(arr[i] > pq.top())
    	    {
    	        pq.pop();
    	        pq.push(arr[i]);
    	    }
    	    cout<<pq.top()<<" ";
    	    i++;
    	}
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends