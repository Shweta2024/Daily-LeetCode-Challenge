## Approach1

```cpp


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int,int>freq; // prefixSum : frequency
        
        for(auto current : nums)
        {
            prefixSum += current;
            
            if(prefixSum == goal)
                ans++;
            
            if(freq[prefixSum-goal])
                ans += freq[prefixSum-goal];
            
            freq[prefixSum]++;
        }
        return ans;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/

```


## Approach2

```cpp


class Solution {
public:
    
    // total number of subarrays with a sum of k
    int totalSubarraysAtmostK(vector<int>&nums, int k)
    {
        int ans = 0;
        int sum = 0;
        int release = 0;
        
        // O(n)
        for(int current = 0; current < nums.size(); current++)
        {
            sum += nums[current];
            
            // invalid window
            while(release <= current && sum > k)
            {
                sum -= nums[release];
                release++;
            }
            
            ans += (current-release+1); 
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return totalSubarraysAtmostK(nums,goal) - totalSubarraysAtmostK(nums,goal-1);
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(1)
*/



```
