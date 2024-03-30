class Solution {
public:
    
    int atMostKDistinct(vector<int>&nums, int k)
    {
        int count = 0;
        int distinct = 0;
        int release = 0;
        unordered_map<int,int>freq; // element : freq
        
        // O(n)
        for(int current = 0; current < nums.size(); current++)
        {
            int currentVal = nums[current];
            if(freq[currentVal] == 0)
                distinct++;
            
            freq[currentVal]++;
            
            // invalid window
            while(distinct > k)
            {
                freq[nums[release]]--;
                if(freq[nums[release]] == 0)
                    distinct--;
                release++;
            }
            
            count += (current-release+1);
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostKDistinct(nums,k) - atMostKDistinct(nums,k-1);
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(n)*/
