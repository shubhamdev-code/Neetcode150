class Solution {
public:
    void subsetSum(int in,vector<int> nums, vector<vector<int>>& subs, vector<int>& curr){
        subs.push_back(curr); 

        for(int i = in; i<nums.size(); i++){
            if(i > in && nums[i] == nums[i-1]) continue; 
            curr.push_back(nums[i]); 
            subsetSum(i+1,nums,subs,curr); 
            curr.pop_back(); 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<vector<int>> ans; 
        vector<int> curr; 
        subsetSum(0,nums,ans,curr); 
        return ans;
    }
};