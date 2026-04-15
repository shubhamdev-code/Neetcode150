
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); 
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++; 
        }

        queue<int> store; 
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) store.push(i); 
        }

        int count = 0; 
        while (!store.empty()) {
            int elem = store.front(); 
            store.pop(); 
            count++; 
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i][1] == elem) {
                    indegree[prerequisites[i][0]]--;
                    if (indegree[prerequisites[i][0]] == 0) {
                        store.push(prerequisites[i][0]); 
                    }
                }
            }
        }
        return count == numCourses;
    }
};