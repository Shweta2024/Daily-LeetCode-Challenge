class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int,int>memo; // elements : freq.
        int ans = 0;
        
        for(auto current : nums)    // O(N)
            memo[current]++;
        
        for(auto current : memo)    // O(N)
        {
            int freq = current.second;
            
            if(freq == 1)
                return -1;
            
            ans += ceil((double)freq/3);
        }
        return ans;
    }
    
};
/*
size of the array -> N
Time Complexity = O(N)
Space Complexity = O(N)
*/
