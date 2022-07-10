// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    void solve(string& str, int n, string& result, int k, int i){
        result = max(result, str);
        
      
        if(i == n or k == 0){
            return;
        }
        
        
        char maxchar = str[i];
        for(int j=i+1; j<n; j++){
            maxchar = max(maxchar, str[j]);
        }
        
        
        if(maxchar > str[i]){
            for(int j=i+1; j<n; j++){
                if(str[j] == maxchar){
                    swap(str[i], str[j]);
                    solve(str, n, result, k-1, i+1);
                    swap(str[i], str[j]);
                }
            }
        }
        else{
            solve(str, n, result, k, i+1);
        }
    }
    
   
    string findMaximumNum(string str, int k)
    {
        int n = str.size();
        string result = str;
        
        solve(str, n, result, k, 0);
        
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends