// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int src,vector<int> &ordered,vector<int> &vis,vector<int> adj[])
    {
        ordered[src] = 1;
        vis[src] = 1;
        for(auto x : adj[src])
        {
            if(!vis[x])
            {
                bool confirm = helper(x,ordered,vis,adj);
                if(confirm) 
                    return true;
            }
            else if(ordered[x]==1)
            {
                return true;
            }
        }
        ordered[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        vector<int> ordered(V,0);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                bool p = helper(i,ordered,vis,adj);
                if(p)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends