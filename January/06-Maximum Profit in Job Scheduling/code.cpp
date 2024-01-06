class Solution {
public:
    
    int maxProfit(int currentIndex, vector<vector<int>>&jobs, vector<int>&startTime, vector<int>&memo)
    {
        if(currentIndex == jobs.size()) return 0;
        
        if(memo[currentIndex] != -1) return memo[currentIndex];
        
        int nextIndex = lower_bound(startTime.begin(),startTime.end(),jobs[currentIndex][1]) - startTime.begin();
        
        // take
        int take = jobs[currentIndex][2] + maxProfit(nextIndex,jobs,startTime,memo);
        
        // not take
        int notTake = maxProfit(currentIndex+1,jobs,startTime,memo);
        
        memo[currentIndex] = max(take,notTake);
        return memo[currentIndex];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<vector<int>>jobs;
        vector<int>memo(n,-1);
        
        for(int index = 0; index < n; index++)
            jobs.push_back({startTime[index],endTime[index],profit[index]});
        
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());
        
        return maxProfit(0,jobs,startTime,memo);
    }
};
/*
Time Complexity = O(2^N*logN)
Space Complexity = O(N)
*/
