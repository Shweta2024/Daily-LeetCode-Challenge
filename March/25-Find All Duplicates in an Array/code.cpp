class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int>ans;
        // O(n)
        for(int index = 0; index <nums.size(); index++)
        {
            nums[abs(nums[index])-1] = - nums[abs(nums[index])-1];
            
            if(nums[abs(nums[index])-1] > 0) ans.push_back(abs(nums[index]));
        }
        return ans;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
