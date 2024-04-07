class Solution {
public:
    bool checkValidString(string s) 
    {
        int open = 0;
        int close = 0;
        
        // every closing bracket there exist an opening bracket
        // O(n)
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] == '(' || s[index] == '*')
                open++;
            else
            {
                if(open == 0)
                    return false;
                else
                    open--;
            }
        }
        
        // every opening bracket these exist a closing brcaket
        //O(n)
        for(int index = s.size()-1; index >= 0; index--)
        {
            if(s[index] == ')' || s[index] == '*')
                close++;
            else
            {
                if(close == 0)
                    return false;
                else
                    close--;
            }
        }
        // VPS
        return true;
        
    }
};
/*
n->size of s
Time Complexity = O(n)
Space Complexity = O(1)
*/
