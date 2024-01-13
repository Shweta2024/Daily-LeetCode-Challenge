class Solution {
public:
    int minSteps(string s, string t)
    {
        unordered_map<char,int>memo;
        
        for(int index = 0; index < s.size(); index++)
        {
            memo[s[index]]++;
            memo[t[index]]--;
        }
        
        int ans = 0;
        for(auto current : memo)
            ans += abs(current.second);
        
        return ans/2;
    }
};

// Time Complexity = O(N+M)
//Space Complexity = O(N+M)
