// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2]; 
        int sumA=0,c[n];
        int sumB=0;
        for(int i=0;i<n;i++){
            sumA+=arr[i];
            c[i]=arr[i];
            sumB+=(i+1);
        }
        sort(c,c+n);
        int i;
        for(i=1;i<n;i++){
            if(c[i]==c[i-1]) break;
        }
        ans[0]=c[i];
        ans[1]=sumB-sumA+ans[0];
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends