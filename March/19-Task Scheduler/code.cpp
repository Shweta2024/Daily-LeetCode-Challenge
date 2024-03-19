
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int time = 0;
        vector<int>freq(26,0);
        
        // populate the freq
        // O(m)
        for(auto current : tasks)
            freq[current-'A']++;
        
        // 26log26 
        sort(freq.begin(),freq.end());
        
        int maxFreq = freq[25];
        int idleTime = (maxFreq-1)*n;
        
        for(int index = 24; index >= 0; index--)
            idleTime -= min(maxFreq-1,freq[index]);
        
        if(idleTime < 0)
            return tasks.size();
        return idleTime+tasks.size();
    }
};

/*
m->size of tasks
Time Complexity = O(m)
Space Complexity = O(26)
*/
