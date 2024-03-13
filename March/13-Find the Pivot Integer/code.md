
## Approach 1

```cpp

class Solution {
public:
    int pivotInteger(int n) 
    {
        int i = 1;
        
        while(i <= n)
        {
            int leftSum = 0;
            int rightSum = 0;
            
            // left sum 1 to i
            for(int j = 1; j <= i; j++)
                leftSum += j;
            
            // right sum i to n
            for(int j = i; j <= n; j++)
                rightSum += j;
            
           if(leftSum == rightSum)
               return i;
            
            i++;
        }
        return -1;
    }
};


/*
Time Complexity = O(n^2)
Space Complexity = O(1)
*/
```

## Approach 2


```cpp

class Solution {
public:
    int pivotInteger(int n) 
    {
        int left = 1;
        int right = n;
        int leftSum = 1;
        int rightSum = n;
        
        if(n == 1) return 1;
        
        while(left < right)
        {
            if(leftSum < rightSum)
            {
                left++;
                leftSum += left;
            }
            else
            {
                right--;
                rightSum += right;
            }
            
            if(leftSum == rightSum && left == right)
                return left;
        }
        return -1;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(1)
*/

```


## Approach 3

```cpp

class Solution {
public:
    int pivotInteger(int n) 
    {
        int sum = n*(n+1)/2;
        int x = sqrt(sum);
        
        if(x*x == sum)
            return x;
        return -1;
    }
};
/*
Time Complexity = O(1)
Space Complexity = O(1)
*/


```
