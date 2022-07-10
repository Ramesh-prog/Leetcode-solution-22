// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends



//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
bool isSafe(int i,int j,int n,vector<int> maze[])
{
    if(i >= 0 && j >= 0 && i < n && j < n) 
    {
        if(i == n - 1 && j == n - 1) return true;
        return maze[i][j];
    }
    return false;
}

bool pathFinder(vector<vector<int>> &result,vector<int> maze[],int i,int j,int n)
{
    if(i == n - 1 && j == n - 1)
    {
        result[i][j] = 1;
        return true;
    }
    for(int k = 1;k <= maze[i][j];k++)
    {
        if(isSafe(i,j + k,n,maze)) 
        {
            if(pathFinder(result,maze,i,j + k,n)) 
            {
                result[i][j] = 1;
                return true;
            }
        }
        if(isSafe(i + k,j,n,maze))
        {
            if(pathFinder(result,maze,i + k,j,n)) 
            {
                result[i][j] = 1;
                return true;
            }
        }
    }
    return false;
}

void solve(int N, vector<int> maze[]) 
{
    // write code here
    vector<int> temp(N,0);
    vector<vector<int>> result(N,temp);
    if(maze[0][0] == 0) 
    {
        cout<<-1<<endl;
        return;
    }
    bool isPath = pathFinder(result,maze,0,0,N);
    if(isPath == false) 
    {
        cout<<-1<<endl;
        return;
    }
    //print(N,result);
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++) cout<<result[i][j]<<" ";
        cout<<endl;
    }
}