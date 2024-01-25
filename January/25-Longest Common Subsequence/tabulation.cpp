class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n+1, vector<int>(m+1,0));
        
        // O(n)
        for(int i = n-1; i >= 0; i--)
        {
            // O(m)
            for(int j = m-1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                {
                    memo[i][j] = 1 + memo[i+1][j+1];
                }
                else
                {
                    memo[i][j] = max(memo[i+1][j],memo[i][j+1]);
                }
            }
        }
        return memo[0][0];
    }
};

/*
Time Complexity = O(n*m)
Space Complexity = O(n*m)*/
