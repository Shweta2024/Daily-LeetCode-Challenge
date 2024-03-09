## Approach 1

```cpp

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int>memo;
        for(auto current : nums1)
            memo[current]++;
        
        for(auto current : nums2)
        {
            if(memo[current])
                return current;
        }
        return -1;
    }
};
/*
m->size of nums1
n->size of nums2
Time Complexity = O(m+n)
Space Complexity = O(m)
*/

```



## Approach 2

```cpp

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;
        
        // O(m+n)
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            
            else if(nums1[i] < nums2[j])
                i++;
            else // nums1[i] > nums2[j]
                j++;
        }
        return -1;
    }
};
/*
m->size of nums1
n->size of nums2
Time Complexity = O(m+n)
Space Complexity = O(1)
*/

```
