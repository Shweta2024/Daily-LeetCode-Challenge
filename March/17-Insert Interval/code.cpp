class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>>ans;
        int index = 0;
        int n = intervals.size();
        
        // no overlapping
        while(index < n && intervals[index][1] < newInterval[0])
        {
            ans.push_back(intervals[index]);
            index++;
        }
        
        // check for overlapping case
        while(index < n && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        ans.push_back(newInterval);
        
        while(index < n)
        {
            ans.push_back(intervals[index]);
            index++;
        }
        return ans;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
