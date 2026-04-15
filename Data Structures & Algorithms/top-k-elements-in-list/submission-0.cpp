class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frq; 
        for(int i =0 ; i < nums.size(); i++){
            frq[nums[i]]++; 
        }

        vector<vector<int>> rev_frq; 
        for(auto i : frq){
            rev_frq.push_back({i.second,i.first}); 
        }

        sort(rev_frq.begin(), rev_frq.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        vector<int> ans; 
        for(int i = 0; i < k; i++){
            int num = rev_frq[i][1]; 
            ans.push_back(num); 
        }
        return ans; 
    }
};
