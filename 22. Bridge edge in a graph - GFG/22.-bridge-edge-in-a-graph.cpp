// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    void isDfs(int u,bool vis[],int c,int d,vector<int> adj[])
    {
       if(vis[u]==false)
       {
           vis[u]=true;
           
           for(int i=0;i<adj[u].size();i++)
           {
                   if(vis[adj[u][i]]==false )
                   {
                        if((u==c && adj[u][i]==d )|| (u==d && adj[u][i]==c))
                            continue;
                        else
                            isDfs(adj[u][i],vis,c,d,adj);
                   }
           }
       }
    }
    
   int isBridge(int V, vector<int> adj[], int c, int d) 
   {
       // Code here
       bool vis[V];
       memset(vis,false,sizeof(vis));
       isDfs(c,vis,c,d,adj);
       if(vis[d])
       return 0;
       return 1;
       
   }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends