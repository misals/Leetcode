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
    void findGoodNodes(TreeNode* root, int &cnt, int maxi) {
        if(root == NULL) {
            return ;
        }
        if(root -> val >= maxi) {
            cnt++;
            maxi = root -> val;
        }
        findGoodNodes(root -> left, cnt, maxi);
        findGoodNodes(root -> right, cnt, maxi);
    }
    
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        if(root == NULL) {
            return cnt;
        }
        findGoodNodes(root, cnt, root -> val);
        
        return cnt;
    }
};