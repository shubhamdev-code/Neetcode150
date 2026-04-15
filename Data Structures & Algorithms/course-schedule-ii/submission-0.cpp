class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0); 
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++; 
        }

        queue<int> store; 
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) store.push(i); 
        }

        vector<int> ans; int cnt = 0; 
        while (!store.empty()) {
            int elem = store.front(); 
            store.pop(); 
            ans.push_back(elem); cnt++; 
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i][1] == elem) {
                    indegree[prerequisites[i][0]]--;
                    if (indegree[prerequisites[i][0]] == 0) {
                        store.push(prerequisites[i][0]); 
                    }
                }
            }
        }
        
        if(cnt!= numCourses) return {}; 
        return ans;
    }
};