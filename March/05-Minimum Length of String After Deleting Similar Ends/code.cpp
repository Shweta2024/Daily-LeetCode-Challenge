class Solution {
public:
    int minimumLength(string s) 
    {
        int start = 0; // prefix
        int end = s.size() - 1; // suffix
        
        // O(n)
        while(start < end && s[start] == s[end])
        {
            char current = s[start];
            
            while(start <= end && s[start] == current)
                start++;
            
            while(end > start && s[end] == current)
                end--;
        }
        return end-start+1;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/
