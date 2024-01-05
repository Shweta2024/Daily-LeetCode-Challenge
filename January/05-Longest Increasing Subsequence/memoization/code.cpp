class Solution {
public:
    
    int findLengthOfLIS(int currentIndex, int prevIndex, vector<int>& nums, vector<vector<int>>&memo)
    {
        if(currentIndex >= nums.size()) return 0;
        
        if(memo[currentIndex][prevIndex+1] != -1) return memo[currentIndex][prevIndex+1];
        
        
        // take
        int take = 0;
        if(prevIndex == -1 || nums[prevIndex] < nums[currentIndex])
            take = 1 + findLengthOfLIS(currentIndex+1,currentIndex,nums,memo);
        
        // not take
        int notTake = 0 + findLengthOfLIS(currentIndex+1,prevIndex,nums,memo);
            
        memo[currentIndex][prevIndex+1] = max(take,notTake);
        return memo[currentIndex][prevIndex+1];
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>memo(n, vector<int>(n+1,-1));
        return findLengthOfLIS(0,-1,nums,memo);
    }
};
/*
-1 -1+1 = 0
0   0+1 = 1
1   1+1 = 2
*/
