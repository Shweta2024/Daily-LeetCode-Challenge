class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        int oneCount = 0;
        string ans = "";
        
        // O(n)
        for(auto current : s)
        {
            if(current == '1')
                oneCount++;
        }
        
        // place oneCount-1 number of 1's at the left
        for(int i = 0; i < oneCount-1; i++)
            ans += "1";
        
        // place the remaing 0's
        int zeroCount = s.size() - oneCount;
        for(int i = 0; i < zeroCount; i++)
            ans += "0";
        
        // place one 1 at the end
        ans += "1";
        
        return ans;
    }
};

/*
n->size of the given string
Time Complexity = O(n)
Space Complexity = O(n)
*/
