class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>ans;
        unordered_map<int,bool>memo; // element : isPresent
        
        // O(m)
        for(auto current : nums1)
            memo[current] = true;
        
        // O(n)
        for(auto current : nums2)
        {
            if(memo[current])
            {
                ans.push_back(current);
                memo[current] = false;
            }
        }
        return ans;
    }
};
/*
m->size of nums1
n->size of nums2
Time Complexity = O(m+n)
Space Complexity = O(m)
*/
