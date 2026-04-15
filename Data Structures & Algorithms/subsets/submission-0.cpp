class Solution {
public: 
    void subsetSum(int i , vector<vector<int>>& ans, vector<int> nums, vector<int>& curr){
        if(i == nums.size()){
            ans.push_back(curr); 
            return ; 
        }
        
        curr.push_back(nums[i]); 
        subsetSum(i+1,ans,nums,curr); 
        curr.pop_back(); 
        subsetSum(i+1,ans,nums,curr); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> curr; 
        subsetSum(0,subs,nums,curr); 
        return subs;

    }
};