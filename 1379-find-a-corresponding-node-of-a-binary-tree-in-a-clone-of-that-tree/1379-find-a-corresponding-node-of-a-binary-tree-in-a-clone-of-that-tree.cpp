/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(original, cloned, target);
    }
    
    TreeNode* search(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned == NULL) {
            return NULL;
        }
        if(original == target) {
            return cloned;
        }
        TreeNode* left = search(original -> left, cloned -> left, target);
        if(left) {
            return left;
        }
        TreeNode* right = search(original -> right, cloned -> right, target);
        if(right) {
            return right;
        }
        return NULL;
    }
};