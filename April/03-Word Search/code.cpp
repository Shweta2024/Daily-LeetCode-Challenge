class Solution {
public:
    
    bool isWordPresent(int currentRow, int currentCol, int currentIndex, vector<vector<char>>&board, string &word)
    {
        // got the word
        if(currentIndex == word.size()) return true;
        
        
        // invalid cell
        if(currentRow < 0 || currentCol < 0 || currentRow >= board.size() || currentCol >= board[0].size() ||
          board[currentRow][currentCol] != word[currentIndex])
            return false;
        
        // mark it as visited
        board[currentRow][currentCol] = '.';
        
        // explore all the possiblies: L,R,U,D
        // 4 ^ (m*n)
        // 4 4 4 4 4= 4^5
        bool ans = isWordPresent(currentRow,currentCol-1,currentIndex+1,board,word) 
        || isWordPresent(currentRow,currentCol+1,currentIndex+1,board,word)
        || isWordPresent(currentRow-1,currentCol,currentIndex+1,board,word)
        || isWordPresent(currentRow+1,currentCol,currentIndex+1,board,word);
        
        // undo the changes
        board[currentRow][currentCol] = word[currentIndex];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int totalRows = board.size();
        int totalCols = board[0].size();
        
        // O(m)
        for(int currentRow = 0; currentRow < totalRows; currentRow++)
        {
            // O(n)
            for(int currentCol = 0; currentCol < totalCols; currentCol++)
            {
                if(board[currentRow][currentCol] == word[0])
                {
                    if(isWordPresent(currentRow,currentCol,0,board,word))
                        return true;
                }
            }
        }
        return false;
    }
};
/*
m->number of rows
n->number of columns
k-> total cells in board // (m*n)
Time Complexity = O((m*n)*4^(m*n)) // exponential
Space Complexity = O(1)
*/
