/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag = true; 
    void dfs(TreeNode* root , long min_left , long  max_right){
        if(!root) return ; 

        if(root->val <= min_left || root->val  >= max_right) flag = false; 
        
        dfs(root->left,min_left,root->val);
        dfs(root->right,root->val,max_right);
    }
    
    bool isValidBST(TreeNode* root) {
        dfs(root , LONG_MIN, LONG_MAX); 
        return flag; 
    }
};