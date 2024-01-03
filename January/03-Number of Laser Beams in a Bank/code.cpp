class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int ans = 0;
        int prev = 0;
        
        for(auto currentString : bank)  // O(m)
        {
            int count = 0;
            for(auto currentChar : currentString)   // O(n)
            {
                if(currentChar == '1')
                    count++;
            }
            if(count != 0)
            {
                ans += prev*count;
                prev = count;
            }
        }
        return ans;
    }
};

/*
size of bank -> m
avg size of a string of bank -> n
Time Complexity = O(m*n)
Space Complexity = O(1)
*/
