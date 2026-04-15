class Solution {
public:
    void findCombinations(int in , int target , vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr){
        if(target == 0){
            ans.push_back(curr); 
            return ;
        }

        for(int i = in; i<candidates.size(); i++){
            if(i > in && candidates[i] == candidates[i-1]) continue; 
            if(candidates[i] > target) break; 
            curr.push_back(candidates[i]); 
            findCombinations(i+1,target-candidates[i],candidates,ans,curr); 
            curr.pop_back(); 
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {   
        sort(candidates.begin(),candidates.end()); 
        vector<vector<int>> combinations; 
        vector<int> curr; 
        findCombinations(0,target,candidates,combinations,curr); 
        return combinations; 
    }
};