class Solution {
public:
    // aaaaaaaaaaaaaaaaaa
    string makeGood(string s) 
    {
        stack<char>container;
        
        // O(n)
        for(auto current : s)
        {
            // they are the same charater but in different cases
            if(!container.empty() && abs(current-container.top()) == 32)
                container.pop();
            else
                container.push(current);
        }
        int n = container.size();
        string ans(n,'.'); // "Us"
        int i = n-1;
        
        // O(n)
        while(!container.empty())
        {
            ans[i] = container.top();
            container.pop();
            i--;
        }
        return ans;
    }
};
/*
n->size of the given string
Time Complexty = O(n)
Space Complexity = O(n)
*/
