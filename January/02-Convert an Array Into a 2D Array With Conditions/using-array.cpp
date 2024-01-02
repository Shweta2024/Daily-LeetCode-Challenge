class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        vector<int>freq(nums.size()+1);
        
        vector<vector<int>>ans;
        
        for(auto current : nums)    // O(N)
        {
            if(freq[current] >= ans.size())
                ans.push_back({});
            
            ans[freq[current]].push_back(current);
            freq[current]++;
        }
        return ans;
    }
};

/*
size of nums -> N
Time Complexity = O(N)
Space Complexity = O(N)*/
