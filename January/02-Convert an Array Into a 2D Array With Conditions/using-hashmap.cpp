class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        unordered_map<int,int>freq;
        
        int rowCount = 0;
        for(auto current : nums)
        {
            freq[current]++;
            rowCount = max(rowCount,freq[current]);
        }
        
        vector<vector<int>>ans(rowCount);
        
        for(auto current : freq)
        {
            for(int index = 0; index < current.second; index++)
                ans[index].push_back(current.first);
        }
        return ans;
    }
};
