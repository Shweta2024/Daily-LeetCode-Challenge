class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int maxLen = 0;
        int release = 0;
        unordered_map<int,int>freq; // element : frequency
        
        // O(n)
        for(int current = 0; current < nums.size(); current++)
        {
            freq[nums[current]]++;
            
            // invalid window
            while(release <= current && freq[nums[current]] > k)
            {
                freq[nums[release]]--;
                release++;
            }
            
            int currentLen = current-release+1;
            maxLen = max(maxLen,currentLen);
        }
        return maxLen;
    }
};
/*
n->size of nums
Time Complexity = O(n)
Space Complexity = O(n)*/
