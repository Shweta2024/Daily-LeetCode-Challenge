class Solution {
public:
    
    bool isVowel(char current)
    {
        if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u' ||
          current == 'A' || current == 'E' || current == 'I' || current == 'O' || current == 'U')
            return true;
        return false;
    }
    
    bool halvesAreAlike(string s) 
    {
        int n = s.size();
        int vowelLeftHalf = 0;
        int vowelRightHalf = 0;
        
        for(int index = 0; index  < n/2; index++)
        {
            // for left half
            if(isVowel(s[index]))
                vowelLeftHalf++;
            
            // for right half
            if(isVowel(s[n/2+index]))
                vowelRightHalf++;
        }
        return vowelLeftHalf == vowelRightHalf;
    }
};

/*

L   E   E   T     |    C    O   D   E
0   1   2   3          4    5   6   7


2 E E   2 O E

vowelLeftHalf = 0
vowelRightHalf = 0
Condition to be alike: they sould have equal no. of vowels

*/
