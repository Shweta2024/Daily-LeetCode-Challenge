class Solution {
public:
    
    // ["aa"]
    bool isValid(string &currentString, unordered_map<char,int>&memo)
    {
        unordered_map<char,int>temp;
        for(auto currentChar : currentString)
        {
            temp[currentChar]++;
            if(memo[currentChar] == 1 || temp[currentChar] > 1)
                return false;
        }
        return true;
    }
    
    void findMaxLen(int currentIndex, string &current, int &maxLen, unordered_map<char,int>&memo, vector<string>&arr)
    {
        int len = current.size();
        maxLen = max(maxLen,len);
        
        if(currentIndex == arr.size()) return ;
        
        //explore possibilities
        for(int index = currentIndex; index < arr.size(); index++)
        {
            string currentString = arr[index];
            if(isValid(currentString,memo))
            {
                int i = 0;
                while(i < currentString.size())
                {
                    current.push_back(currentString[i]);
                    memo[currentString[i]]++;
                    i++;
                }
                
                findMaxLen(index+1,current,maxLen,memo,arr);
                
                // undo changes
                i = currentString.size();
                while(i--)
                {
                    current.pop_back();
                    memo[currentString[i]]--;
                }
            }
        }
        return ;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int maxLen = 0;
        string current = "";
        unordered_map<char,int>memo;
        
        findMaxLen(0,current,maxLen,memo,arr);
        
        return maxLen;
    }
};

// Time Complexity = O(2^N)
// Space Complexity = O(N)
