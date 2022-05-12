class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int m = s.size();
            int n = p.size();
            vector<bool> dp(n + 1, 0);
            dp[0] = 1;

            for (int i = 1; i <= n; i++)
            {
                dp[i] = i > 1 && ('*' == p[i - 1]) && dp[i - 2];
            }

            bool left_up;
            for (int i = 0; i < m; i++)
            {
                left_up = dp[0];
                dp[0] = 0;
                for (int j = 0; j < n; j++)
                {
                    int up = dp[j + 1];
                    if (p[j] != '*') dp[j + 1] = (s[i] == p[j] || '.' == p[j]) && left_up;
                    else dp[j + 1] = dp[j - 1] || dp[j + 1] && (s[i] == p[j - 1] || '.' == p[j - 1]);
                    left_up = up;
                }
            }
            return dp[n];
        }
};