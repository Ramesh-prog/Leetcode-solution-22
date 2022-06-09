class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int l = 0;
            int r = height.size() - 1; 
            int water = 0;
            int minHeight = 0;
            while (l < r)
            {
                while (l < r && height[l] <= minHeight)
                {
                    water += minHeight - height[l++];
                }
                while (l < r && height[r] <= minHeight)
                {
                    water += minHeight - height[r--];
                }
                minHeight = min(height[l], height[r]);
            }
            return water;
        }
};