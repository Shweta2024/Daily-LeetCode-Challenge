> We have to find out the ***total count of elements*** in ``nums`` that has the _**max frequency**_.

### Example 1:

 **Input**: nums = [1,2,2,3,1,4]

 **Output**: 4

 **Explanation**: 

| Elements | Frequency |
|----------|----------|
| 1 | 2 |
| 2 | 2 |
| 3 | 1 |
| 4 | 1 |



 In the above example you can clearly see that, element 1 & 2 has the max frequency(i.e. 2). So, the **total number of elements with max frequency is 4**, as we'll be adding two 2 and two 1.

<br>


## Approach 1

- Store the frequencies of each elements in a hashmap and while doing so find out the ``maxFrequency``.
- Now, itearte over the hashmap and _add the frequencies of all the elements to ``ans`` that has a frequency equal to maxFrequency_.
- Return ans.

<br>

## Complexity Analysis

- Time Complexity = O(n), as we are iterating over the entire array to store the frequency of each elements.
- Space Complexity = O(n), in the worst case all the elements of nums can be distinct as a result of which we'll have a total of n entires in the hashmap.


<br>



## Code

```cpp

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int ans = 0;
        int maxFrequency = -1;
        unordered_map<int,int>memo;
        
        // storing frequencies of each element in the hashmap
        // and finding the maxFrequency
        for(auto current : nums)
        {
            memo[current]++;
            maxFrequency = max(maxFrequency,memo[current]);
        }
        
        // adding the frequencies of all elements to ans that has a frequency equal to maxFrequency 
        for(auto current : memo)
        {
            if(current.second == maxFrequency)
                ans += current.second;
        }
        return ans;
    }
};



```

<hr>


## Approach 2

- Take two variables :
    - `` ans ``: initially as 0, it will be used to store the final result, i.e. the count of total element with max frequency.
    - `` maxFrequency ``: initially as 0, it will be used to keep track of the max frequency.
 
- Iterate over `` nums ``, to find the frequency of each element say `` currentFrequency ``.
- If _currentFrequency becomes greater than the maxFrequency_, then update `` maxFrequency `` and ans with `` currentFrequency ``.
- Else if the _currentFrequency is equal to the maxFrequency_, then simply add it to ``ans``.
- Finally return ans.

<br>

## Complexity Analysis

- Time Complexity = O(n), as we are iterating over the entire array to store the frequency of each elements.
- Space Complexity = O(n), in the worst case all the elements of nums can be distinct as a result of which we'll have a total of n entires in the hashmap.

<br>

## Code

```cpp


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int ans = 0;
        int maxFrequency = 0;
        unordered_map<int,int>memo;
        
        for(int index = 0; index < nums.size(); index++)
        {
            memo[nums[index]]++;
            int currentFrequency = memo[nums[index]];
            
            // if currentFrequency is greater than maxFrequency then update maxFrequency and ans
            if(currentFrequency > maxFrequency)
            {
                maxFrequency = currentFrequency;
                ans = currentFrequency;
            }
            
            // otherwise, if currentFrequency is equal to maxFrequency, then simply add it to ans
            else if( currentFrequency == maxFrequency)
                ans += currentFrequency;
        }
        return ans;
    }
};


```
