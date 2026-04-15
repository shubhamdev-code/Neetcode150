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
    int dfsHeight(TreeNode* root , int& max_d){
        if(!root) return 0; 
        
        int left_height = dfsHeight(root->left,max_d); 
        int right_height = dfsHeight(root->right,max_d);
        max_d = max(left_height+right_height,max_d); 
        return max(left_height,right_height) + 1; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0; 
        
        int ans  = 0; 
        dfsHeight(root,ans);
        
        return ans; 
    }
};