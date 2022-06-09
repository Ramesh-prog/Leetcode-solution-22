class Solution
{
    public:
        vector<int> countBits(int num)
        {
            vector<int> sol(num + 1, 0);
            for (int i = 1; i <= num; ++i)
                sol[i] = sol[i &(i - 1)] + 1;
            return sol;
        }
};