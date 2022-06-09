// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        priority_queue<int, vector<int>, greater<int>> mint;
        vector<int>res;
        
        for(int i=0;i<num;i++)
        {
            mint.push(arr[i]);
            
            if(mint.size()>k)
            {
                res.push_back(mint.top());
                mint.pop();
            }
        }
        
        while(mint.size())
        {
            res.push_back(mint.top());
            mint.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends