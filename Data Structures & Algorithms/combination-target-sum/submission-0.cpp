class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int i, int target, int curr_sum, vector<int>& curr) {
        if (curr_sum == target) {
            ans.push_back(curr);
            return;
        }

        if (i >= nums.size() || curr_sum > target) {
            return;
        }

        curr.push_back(nums[i]);
        backtrack(ans, nums, i, target, curr_sum + nums[i], curr); // Stay at i (can pick same number)
        curr.pop_back();

        backtrack(ans, nums, i + 1, target, curr_sum, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, candidates, 0, target, 0, curr);
        return ans;
    }
};