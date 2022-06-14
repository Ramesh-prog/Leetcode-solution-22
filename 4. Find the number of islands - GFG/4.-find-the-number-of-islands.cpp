// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n,m;
    int dx[8] = {0,0,1,-1,-1,-1,1,1};
    int dy[8] = {-1,1,0,0,-1,1,-1,1};
    void fun(vector<vector<char>>&grid,int i,int j)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j] == '1')
        {
            grid[i][j] = '0';
            for(int k = 0;k<8;k++)
            {
                fun(grid,i+dx[k],j+dy[k]);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    fun(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends