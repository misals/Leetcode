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
    vector<string> ans;
    void traverse(TreeNode* root, string s)
    {
        if(root == NULL) return;
        s = s + to_string(root->val)+"->";
        if(root -> left == NULL && root -> right == NULL)
        {
            s.resize(s.size()-2);
            ans.push_back(s);
        }
        traverse(root -> left, s);
        traverse(root -> right, s);
        s.resize(s.size() - 1);
     }
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root, "");
        return ans;
    }
};