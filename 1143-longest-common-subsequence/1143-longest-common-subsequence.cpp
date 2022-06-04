class Solution
{
    public:
        int longestCommonSubsequence(string text1, string text2)
        {
            int n = text1.size();
            int m = text2.size();
            vector<vector < int>> lookup(n + 1, vector<int> (m + 1, 0));

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (text1[i - 1] == text2[j - 1])
                        lookup[i][j] = 1 + lookup[i - 1][j - 1];
                    else
                        lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
                }
            }
            return lookup[n][m];
        }
};