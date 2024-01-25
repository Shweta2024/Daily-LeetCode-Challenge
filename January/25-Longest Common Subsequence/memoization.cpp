class Solution {
public:
    
    int findLCS(int i, int j, string &s1, string &s2, vector<vector<int>>&memo)
    {
        if(i == s1.size() || j == s2.size()) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        //take
        if(s1[i] == s2[j])
        {
            memo[i][j] = 1 + findLCS(i+1,j+1,s1,s2,memo);
            return memo[i][j];
        }
        
        //not take
        // skip characters of s2
        // skip characters of s1
        return memo[i][j] = max(findLCS(i,j+1,s1,s2,memo),findLCS(i+1,j,s1,s2,memo));
    }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n, vector<int>(m,-1));
        return findLCS(0,0,text1,text2,memo);
    }
};
