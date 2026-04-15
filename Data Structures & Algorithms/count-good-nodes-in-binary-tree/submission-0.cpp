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
    int goodNodes(TreeNode* root) {
        if(!root) return 0; 
        queue<pair<TreeNode*,int>> store; 
        
        store.push({root,root->val});
        int ans = 0; 
        while(!store.empty()){
            int sz = store.size(); 
            for(int i = 0; i<sz; i++){
                TreeNode* curr_root = store.front().first; int mx = store.front().second;  
                if(mx <= curr_root->val) ans++;
                store.pop(); 
                if(curr_root->left) store.push({curr_root->left,max(mx,curr_root->left->val)}); 
                if(curr_root->right) store.push({curr_root->right,max(mx,curr_root->right->val)});
            }
        }
        return ans; 
    }
};