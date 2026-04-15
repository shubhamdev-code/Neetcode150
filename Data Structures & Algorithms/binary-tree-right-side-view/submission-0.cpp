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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {}; 

        queue<TreeNode*> store; vector<int> ans; 
        store.push(root); 
        while(!store.empty()){
            int sz = store.size(); 
            for(int i = 0 ; i < sz; i++){
                TreeNode* curr = store.front(); 
                store.pop(); if(i == sz-1) ans.push_back(curr->val);
                if(curr->left) store.push(curr->left); 
                if(curr->right) store.push(curr->right); 
            }
        }
        return ans; 
    }
};