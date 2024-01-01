class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookieSize)
    {
        sort(greed.begin(), greed.end());   // O(nlogn)
        sort(cookieSize.begin(), cookieSize.end()); // O(mlogm)
        
        int currentChild = 0;
        int currentCookie = 0;
        
        while(currentChild < greed.size() && currentCookie < cookieSize.size())     // O(n + m)
        {
            if(greed[currentChild] <= cookieSize[currentCookie])
                currentChild++;
            
            currentCookie++;
        }
        return currentChild;
    }
};

/*
size of greed -> n
size of cookieSize -> m

Time Complexity = O(nlogn + mlogm)
Space Complexity = O(logn + logm)
*/
