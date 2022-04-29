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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            root = temp;
            return root;
        }
        
        TreeNode* curr = root;
        TreeNode* node;
        
        while(curr != NULL){
            if(val > curr -> val){
                node = curr;
                curr = curr -> right;
            }
            else{
                node = curr;
                curr = curr -> left;
            }
                
        }
        
        if(val > node -> val){
            TreeNode* temp = new TreeNode(val);
            node -> right = temp;
        }
        else{
            TreeNode* temp = new TreeNode(val);
            node -> left = temp;
        }
        return root;
        
    }
};