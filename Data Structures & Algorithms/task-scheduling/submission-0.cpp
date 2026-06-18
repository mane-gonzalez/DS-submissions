class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26);
        int maxFreq = 0;
        int mostFreq = 0;

        for(int i = 0; i < tasks.size(); i++){
            map[tasks[i] - 'A']++;

            maxFreq = max(maxFreq, map[tasks[i] - 'A']);
        }

        for(int i = 0; i < map.size(); i++){
            if(maxFreq == map[i])
                mostFreq++;
        }

        int result = (maxFreq - 1)*(n + 1) + mostFreq;

        return max(result, (int)tasks.size());
    }
};
