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
    bool preOrder(TreeNode* root, int k, map<int,int> &mp) {
        if(root == NULL) {
            return false;
        }
        if(preOrder(root -> left, k, mp))
            return true;
        if(mp.find(k - root -> val) != mp.end()) {
            return true;
        }
        mp[root-> val] = 1;
        if(preOrder(root -> right, k, mp))
            return true;
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        map<int, int> mp;
        return preOrder(root, k, mp);
    }
};