class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        
        for(int j=0;j<points.size();j++){
            int a=points[j][0],b=points[j][1];
            pq.push({sqrt(pow(a,2)+pow(b,2)),{a,b}});
        }
        
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};