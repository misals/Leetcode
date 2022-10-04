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
    string ans = "";
    
    void inorder(TreeNode* root, string &s) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            s.push_back('a' + root -> val);
            reverse(s.begin(), s.end());
            if(ans == "") {
                ans = s;
            }
            else {
                ans = min(ans, s);
            }
            reverse(s.begin(), s.end());
            s.pop_back();
            return;
        }
        s.push_back('a' + root -> val);
        inorder(root -> left, s);
        inorder(root -> right, s);
        s.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string s;
        inorder(root, s);
        
        return ans;
    }
};