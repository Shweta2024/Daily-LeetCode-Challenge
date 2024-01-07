class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<long long,int>>memo(n);
        
        for(int currentIndex = 1; currentIndex < n; currentIndex++) // O(n)
        {
            for(int prevIndex = 0; prevIndex < currentIndex; prevIndex++)   // O(n)
            {
                long long difference = (long long)nums[currentIndex] - (long long)nums[prevIndex];
                ans += memo[prevIndex][difference];
                memo[currentIndex][difference] += memo[prevIndex][difference]+1;
            }
        }
        return ans;
    }
};
/*
Time Complexity = O(n*n)
Space Complexity = O(n*n)
*/
