
## CODE 1 : using Hashmap & Stack

```cpp

class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int open = 0;
        // identifying invalid closing
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] == '(')
                open++;
            else if(s[index] == ')')
            {
                if(open == 0)
                    s[index] = '*';
                else
                    open--;
            }
        }
        
        int close = 0;
        // identify invalid opening 
        for(int index = s.size()-1; index >= 0; index--)
        {
            if(s[index] == ')')
                close++;
            else if(s[index] == '(')
            {
                if(close == 0)
                    s[index] = '*';
                else
                    close--;
            }
        }
        
        string ans = "";
        for(auto current : s)
        {
            if(current != '*')
                ans += current;
        }
        return ans;
    }
};
/*
Time Complexity = O(n)
Space Complexity = O(2n)*/

```

## CODE 2 : using Stack

```cpp

class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int>stk; // index of opening : invalid opening
        
        // marked invalid parenthese with *
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] == '(')
                stk.push(index);
            else if(s[index] == ')')
            {
                if(stk.empty())
                    s[index] = '*';
                else
                    stk.pop();
            }
        }
        while(!stk.empty())
        {
            s[stk.top()] = '*';
            stk.pop();
        }
        
        // populate our ans
        string ans = "";
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] != '*')
                ans += s[index];
        }
        return ans;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(n)*/

```


## CODE 3 : without extra space 

```cpp

class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char,int>>stk; // element : index
        
        // identify invalid parenthese
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] == '(')
                stk.push({s[index],index});
            else if(s[index] == ')')
            {
                if(!stk.empty() && stk.top().first == '(') // {'(',0}
                    stk.pop();
                else
                    stk.push({s[index],index});
            }
        }
        
        unordered_map<int,bool>memo; // index : ture/false
        while(!stk.empty())
        {
            memo[stk.top().second] = true;
            stk.pop();
        }
        
        // populate our ans
        string ans = "";
        for(int index = 0; index < s.size(); index++)
        {
            if(!memo[index])
                ans += s[index];
        }
        return ans;
    }
};

/*
n->size of s
Time Complexity = O(n)
Space Complexity = O(1)*/

```
