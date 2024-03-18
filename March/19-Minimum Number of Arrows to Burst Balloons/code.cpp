class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int arrows = 1;
        sort(points.begin(), points.end());
        
        vector<int>prev(2,0);
        prev[0] = points[0][0];
        prev[1] = points[0][1];
        
        //  O(n)
        for(int index = 1; index < points.size(); index++)
        {
            int currentStart = points[index][0];
            int currentEnd = points[index][1];
            
            int prevStart = prev[0];
            int prevEnd = prev[1];
            
            // non-overlapping
            if(prevEnd < currentStart)
            {
                arrows++;
                prev[0] = currentStart;
                prev[1] = currentEnd;
            }
            else // overlapping
            {
                prev[0] = max(prevStart,currentStart);
                prev[1] = min(prevEnd,currentEnd);
            }
        }
        return arrows;
    }
};
/*
n->size of given 2D vector
Time Complexity = O(n)
Space Complexity = O(1)
*/
