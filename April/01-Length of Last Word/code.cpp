class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        
        // O(n)
        for(int index = s.size()-1; index >= 0; index--)
        {
            // ignored unwanted spaces
            if(s[index] == ' ' && ans == 0)
                continue;
            
            else if(s[index] == ' ') // ans != 0
                return ans;
            
            ans++;
        }
        return ans;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(1)


"hey                  "
*/
