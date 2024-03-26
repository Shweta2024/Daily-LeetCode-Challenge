class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        bool isPresentOne = false;
        
        // remove unnecessary values: x <= 0 || x > n
        // track if 1 is present
        // O(n)
        for(int index = 0; index < n; index++)
        {
            if(nums[index] == 1)
                isPresentOne = true;
            
            else if(nums[index] <= 0 || nums[index] > n)
                nums[index] = 1;
        }
        
        if(!isPresentOne) return 1;
        
        // O(n)
        for(int index = 0; index < n; index++)
        {
            if(abs(nums[index]) == n)
                nums[0] = -abs(nums[0]);
            
            else
                nums[abs(nums[index])] = -abs(nums[abs(nums[index])]);
        }
        
        // O(n)
        for(int index = 1; index < n; index++)
        {
            if(nums[index] > 0)
                return index;
        }
        
        if(nums[0] > 0) return n;
        
        return n+1;
    }
};
/*
n->size of nums
Time Complexity = O(n)
Space Complexity = O(1)*/
