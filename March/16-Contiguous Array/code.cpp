class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int maxLen = 0;
        int prefixSum = 0;
        unordered_map<int,int>memo; // prefixSum : index
        memo[0] = -1; // [0,1]
        
        // O(n)
        for(int index = 0; index < nums.size(); index++)
        {
            if(nums[index] == 0)
                prefixSum--;
            else
                prefixSum++;
            
            if(memo.find(prefixSum) != memo.end())
            {
                int currentLen = index - memo[prefixSum];
                maxLen = max(maxLen,currentLen);
            }
            else
                memo[prefixSum] = index;
        }
        return maxLen;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
