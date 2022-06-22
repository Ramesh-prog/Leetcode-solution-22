// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool bfs(vector<int>adj[],int i,vector<bool>visited)
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        visited[i]=true;
        while(!q.empty())
        {
            int x=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto y:adj[x])
            {
                if(!visited[y])
                 {
                  q.push({y,x});
                     visited[y]=true;  
                 }
                 else if( y!=par)
                 {
                     return true;
                 }
            }
            
        }
        return false;
    }
     bool isCycle(int V, vector<int> adj[]) 
     {
       vector<bool>visited(V,false);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               if(bfs(adj,i,visited))
                return true;
           }
       }
       return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends