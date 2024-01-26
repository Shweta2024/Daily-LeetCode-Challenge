class Solution {
public:
    int mod = 1e9+7;
    int totalWays(int currentRow, int currentCol, int moves, int maxMove, int m, int n,
                 vector<vector<vector<int>>>&memo)
    {
        // ball is out of the boundary
        if((currentRow < 0 || currentCol < 0 || currentRow >= m || currentCol >= n) && moves <= maxMove)
            return 1;
        
        if(moves >= maxMove)
            return 0;
        
        if(memo[currentRow][currentCol][moves] != -1) return memo[currentRow][currentCol][moves];
        
        // explore the 4 possiities
        int up = totalWays(currentRow-1,currentCol,moves+1,maxMove,m,n,memo);
        int down = totalWays(currentRow+1,currentCol,moves+1,maxMove,m,n,memo);
        int left = totalWays(currentRow,currentCol-1,moves+1,maxMove,m,n,memo);
        int right = totalWays(currentRow,currentCol+1,moves+1,maxMove,m,n,memo);
        
        memo[currentRow][currentCol][moves] = (((up+down)%mod)+((left+right)%mod))%mod;
        return memo[currentRow][currentCol][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>>memo(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return totalWays(startRow,startColumn,0,maxMove,m,n,memo);
    }
};

/*
Time Complexity = O(m*n*maxMove)
Space Complexity = O(m*n*maxMove)
*/
