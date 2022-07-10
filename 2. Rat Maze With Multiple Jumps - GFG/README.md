# 2. Rat Maze With Multiple Jumps
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">A Maze is given as <strong>N*N</strong>&nbsp;matrix of blocks where source block is the upper left most block i.e., <strong>maze[0][0]</strong> and destination block is lower rightmost block i.e., <strong>maze[N-1][N-1]</strong>. Find if it is possible for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].</span></p>

<p><span style="font-size:18px"><strong>Note:</strong><br>
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.<br>
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
maze[][] = {{2,1,0,0},{3,0,0,1},
{0,1,0,1},{0,0,0,1}}
<strong>Output:
</strong>1 0 0 0
1 0 0 1
0 0 0 1
0 0 0 1<strong>
Explanation: </strong>Rat started with m[0][0] and
can jump up to 2 steps right/down. First
check m[0][1] as it is 1, next check
m[0][2], this won't lead to the solution.
Then check m[1][0], as this is 3(non-zero)
so we can make 3 jumps to reach m[1][3].
From m[1][3] we can move downwards taking
1 jump each time to reach destination at
m[3][3]. </span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
maze[][] = {{2,1,0,0}{2,0,0,1},
{0,1,0,1},{0,0,0,1}}
<strong>Output: </strong>-1<strong>
Explanation: </strong>As no path exists, so -1.</span></pre>

<p><span style="font-size:18px"><strong>Your task</strong>:<br>
You don't need to read input or print anything. Your task is to&nbsp;complete the function <strong>solve()</strong> which takes the Maze and its dimensions N as inputs and prints the valid path if it exists. If it does not exist, print -1<br>
<strong>Note:&nbsp;</strong>In the valid path, for each block, if you are visiting the block then you should print 1 for it else 0.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N<sup>N</sup>).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N) if we don't consider the solution matrix for this.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 &lt;= n &lt;= 50<br>
0 &lt;= maze[i][j] &lt;= 20</span></p>
 <p></p>
            </div>