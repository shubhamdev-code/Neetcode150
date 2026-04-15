class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) return true; 
        if (!root || !subroot || root->val != subroot->val) return false; 

        return isSame(root->left, subroot->left) && isSame(root->right, subroot->right); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
