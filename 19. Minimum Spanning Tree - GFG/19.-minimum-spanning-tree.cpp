// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int node, vector<int> &parent)
	{
	    if(node == parent[node])
	    {
	        return node;
	    }
	    
        parent[node] = findParent(parent[node], parent);
        return parent[node];
	}
	
	void unionize(int a, int b, vector<int> &parent, vector<int> &rank)
	{
	    int aParent = findParent(a, parent);
	    int bParent = findParent(b, parent);
	    
	    if(rank[aParent] < rank[bParent])
	    {
	        parent[aParent] = bParent;
	    }
	    else if (rank[aParent] > rank[bParent])
	    {
	        parent[bParent] = aParent;
	    }
	    else 
	    {
	        parent[bParent] = aParent;
	        rank[aParent]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        
        for(int i = 0; i < V; i++)
        {
            for(auto x: adj[i])
            {
                edges.push_back({i, x[0], x[1]});
            }
        }
        
        // don't forget to use const and & to reduce time complexity
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });
        
        vector<int> parent(V);
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        
        vector<int> rank(V, 0);
        
        int ans = 0;
        for(auto edge: edges)
        {
            if(findParent(edge[1], parent) != findParent(edge[0], parent))
            {
                unionize(edge[0], edge[1], parent, rank);
                ans += edge[2];
            }
        }
        
        return ans;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends