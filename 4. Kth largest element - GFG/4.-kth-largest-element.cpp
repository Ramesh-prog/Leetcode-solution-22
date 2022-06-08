// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return kth largest element from an array.
    int KthLargest(int arr[], int n, int k) {
        // Your code here
        priority_queue<int> pq(arr, arr+n);
        for(int i = 0; i<k-1;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
}  // } Driver Code Ends