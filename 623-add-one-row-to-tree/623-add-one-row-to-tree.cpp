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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(depth > 2) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if(node -> left != NULL) {
                    q.push(node -> left);
                }
                if(node -> right != NULL) {
                    q.push(node -> right);
                }
            }
            depth--;
        }
        
        int n = q.size();
        for(int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            
            leftNode -> left = node -> left;
            rightNode -> right = node -> right;
            
            node -> left = leftNode;
            node -> right = rightNode;
        }
        return root;
        
    }
};