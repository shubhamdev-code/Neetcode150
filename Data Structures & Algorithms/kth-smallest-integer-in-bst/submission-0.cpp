class Solution {
public:
    vector<int> arr; 
    void dfs(TreeNode* root){
        if(!root) return ; 
        
        dfs(root->left); 
        arr.push_back(root->val); 
        dfs(root->right); 
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root); 
        return arr[k-1];
    }
};
