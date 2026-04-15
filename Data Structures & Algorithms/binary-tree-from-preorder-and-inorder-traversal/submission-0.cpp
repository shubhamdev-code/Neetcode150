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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        unordered_map<int,int> in;
        for (int i=0; i< inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1, in);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right, unordered_map<int,int> &hmap) {
        if(left > right) return nullptr;
        
        int pivot = hmap[preorder[rootIdx]];
        TreeNode* root = new TreeNode(preorder[rootIdx]);
        rootIdx++;
        
        root->left = build(preorder, inorder, rootIdx, left, pivot-1, hmap);
        root->right = build(preorder, inorder, rootIdx, pivot+1, right, hmap);
             
        return root;
    }
};
