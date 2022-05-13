// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n)
    {
        // code here
        const long long int M = 1000000007;
        long long int fib[n];
        
        fib[1] = 1;
        fib[2] = 1;
        
        for(long long int i = 3;i<=n;i++)
        {
            fib[i] = fib[i-1]%M + fib[i-2]%M;
        }
        return fib[n]%M;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends