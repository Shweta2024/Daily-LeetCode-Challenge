class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int score = 0;
        int start = 0;
        int end = tokens.size()-1;
        
        // O(nlogn)
        sort(tokens.begin(),tokens.end());
        
        // O(n)
        while(start <= end)
        {
            //face up
            if(tokens[start] <= power)
            {
                score++;
                power -= tokens[start];
                start++;
            }
            // face down
            else if(start < end && score >= 1)
            {
                score--;
                power += tokens[end];
                end--;
            }
            else
                return score;
        }
        return score;
    }
};
/*
n -> size of the tokens array
Time Complexity = O(nlogn)
Space Complexity = O(logn)
*/
