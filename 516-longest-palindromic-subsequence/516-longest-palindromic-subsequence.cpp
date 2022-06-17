class Solution
{
    public:
        int longestPalindromeSubseq(string s)
        {
            string w = s;
            reverse(s.begin(), s.end());
            int m = s.size();
            int dp[m + 1][m + 1];
            for (int i = 0; i < m + 1; i++)
            {
                dp[i][0] = 0;
            }
            for (int i = 0; i < m + 1; i++)
            {
                dp[0][i] = 0;
            }
            for (int i = 1; i < m + 1; i++)
            {
                for (int j = 1; j < m + 1; j++)
                {
                    if (s[i - 1] == w[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[m][m];
        }
};