class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);

        vector<int> prod = nums; 
        vector<int> rev_prod = nums;  
        for(int i = 1;  i < nums.size(); i++){
            prod[i] *= prod[i-1]; 
        }

        for(int i = nums.size()-2; i>=1 ; i--){
            rev_prod[i] *= rev_prod[i+1]; 
        }

        for(int i = nums.size()-1; i>=0;  i--) cout<<rev_prod[i]<<' '; 

        ans[0] = rev_prod[1]; ans[nums.size()-1] = prod[nums.size()-2]; 
        for(int i = 1 ; i <nums.size()-1; i++){
            ans[i] = rev_prod[i+1] * prod[i-1];
        }
        return ans;
    }
};
