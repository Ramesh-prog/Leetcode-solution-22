// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
   bool issafe(int grid[N][N],int i,int j,int k){
        for(int c=0;c<9;c++){
            if(grid[i][c]==k) return false;
        }
        for(int r=0;r<9;r++){
            if(grid[r][j]==k) return false;
        }
        int rs=(i/3)*3;
        int cs=(j/3)*3;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(grid[rs+r][cs+c]==k) return false;
            }
        }
        return true;
    }
    bool solve(int grid[N][N],int i,int j){
        if(i==N) return true; 
        if(j==N){
            i++;
            j=0;
        }
        if(grid[i][j]>0) return solve(grid,i,j+1);
        for(int k=1;k<=9;k++){
            if(issafe(grid,i,j,k)){
                grid[i][j]=k;
                if(solve(grid,i,j+1)) return true;
                grid[i][j]=0;
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
         return solve(grid,0,0);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends