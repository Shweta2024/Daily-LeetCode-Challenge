class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int maxLen = 1;
        vector<int>dp(nums.size(),1);
        
        for(int currentIndex = 1; currentIndex < nums.size(); currentIndex++)
        {
            for(int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            {
                if(nums[prevIndex] < nums[currentIndex])
                {
                    dp[currentIndex] = max(dp[currentIndex],dp[prevIndex]+1);
                    maxLen = max(maxLen, dp[currentIndex]);
                }
            }
        }
        return maxLen;
    }
};
/*
Time Complexity = O(N^2)
Space Complexity = O(N)
*/
