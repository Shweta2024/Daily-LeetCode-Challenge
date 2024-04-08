class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int wantsCircular = 0;
        int wantsSquare = 0;
        
        // O(n)
        for(auto current : students)
        {
            if(current == 0)
                wantsCircular++;
            else
                wantsSquare++;
        }
        
        // O(n)
        for(auto current : sandwiches)
        {
            if(current == 0)
            {
                if(wantsCircular == 0)
                    return wantsSquare;
                else
                    wantsCircular--;
            }
            else // current == 1
            {
                if(wantsSquare == 0)
                    return wantsCircular;
                else
                    wantsSquare--;
            }
        }
        return 0;
    }
};
/*
n -> size of the given array
Time Complexity = O(n)
Space Complexity = O(1)*/
