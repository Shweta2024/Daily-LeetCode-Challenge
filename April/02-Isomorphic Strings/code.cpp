class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char>m1; // s -> t
        unordered_map<char,char>m2; // t -> s
        
        // O(n)
        for(int index = 0; index < s.size(); index++)
        {
            if(m1[s[index]] && m1[s[index]] != t[index]) return false;
            if(m2[t[index]] && m2[t[index]] != s[index]) return false;
            
            m1[s[index]] = t[index];
            m2[t[index]] = s[index];
        }
        return true;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
