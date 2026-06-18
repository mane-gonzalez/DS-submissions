class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto pre:prerequisites){
            int course = pre[0];
            int prereq = pre[1];

            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        int takenCourses = 0;

        while(!q.empty()){
            int course = q.front();
            q.pop();
            takenCourses++;

            for(auto nextCourse:graph[course]){
                inDegree[nextCourse]--;

                if(inDegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }

        return takenCourses == numCourses;
    }
};
