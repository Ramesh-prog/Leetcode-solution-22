class Solution
{
    public:
        int getMaxLen(vector<int> nums)
        {
            int start = -1, first_negative = -2, len = 0, negative = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)	// reset everytime if zero
                {
                    negative = 0;
                    start = i;
                    first_negative = -2;
                }
                else
                {
                    if (nums[i] < 0) 
                        negative++;	// number of negatives in  current frame means 
                    if (negative == 1 && first_negative == -2) 
                        first_negative = i;	// init firstneg cnt neg;
                    if (negative % 2 == 0)
                        len = max(len, i - start);	//if curr cnt neg is framestart;
                    else 
                        len = max(len, i - first_negative);	// first firstneg after last zero;
                }
            }
            return len;
        }
};