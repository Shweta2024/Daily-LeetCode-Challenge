## Approach 1

```cpp


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,0);
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        
        for(int index = 1; index < n; index++)
            prefix[index] = prefix[index-1] * nums[index-1];
        
        for(int index = n-2; index >= 0; index--)
            suffix[index] = suffix[index+1]*nums[index+1];
        
        for(int index = 0; index < n; index++)
            ans[index] = prefix[index] * suffix[index];
        
        return ans;
    }
};

/*
n->size of the array
Time Complexity = O(3n) => O(n)
Space Complexity = O(2n) => O(n)
*/

```

## Approach 2

```cpp


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,1);
        
        // store prefix product in ans
        for(int index = 1; index < n; index++)
            ans[index] = ans[index-1] * nums[index-1];
        
        int suffix  = 1;
        for(int index = n-1; index >= 0; index--)
        {
            ans[index] = ans[index] * suffix;
            suffix *= nums[index];
        }
        
        return ans;
    }
};
/*
n->size of the array
Time Complexity = O(2n) => O(n)
Space Complexity = O(1)
*/



```
