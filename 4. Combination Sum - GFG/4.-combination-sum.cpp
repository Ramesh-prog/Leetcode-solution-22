// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
   void dfs(vector<vector<int>> &res, vector <int> &v, vector <int> &A, int B, int i){
        if(i == A.size() ){
            if(B == 0)
                res.push_back(v);
            return;
        }
        if(B >= A[i]){
            v.push_back(A[i]);
            dfs(res, v, A, B-A[i], i);
            v.pop_back();
        }
        dfs(res, v, A, B, i+1);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        auto ip1 = unique(A.begin(), A.end());
        A.resize(distance(A.begin(), ip1));
        vector<vector <int>> res;
        vector <int> v;
        dfs(res, v, A, B, 0);
        sort(res.begin(), res.end());
        auto ip2 = unique(res.begin(), res.end());
        res.resize(distance(res.begin(), ip2));
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends