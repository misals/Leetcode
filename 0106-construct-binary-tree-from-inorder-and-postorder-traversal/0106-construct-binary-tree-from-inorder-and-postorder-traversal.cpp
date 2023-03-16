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
    TreeNode* build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &mp) {
        if(inStart > inEnd || postStart > postEnd) {
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[postEnd]);
        
        int inRoot = mp[node -> val];
        int numsLeft = inRoot - inStart;
        
        node -> left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, mp);
        
        node -> right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n = inorder.size();
        
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
        
        return root;
    }
};