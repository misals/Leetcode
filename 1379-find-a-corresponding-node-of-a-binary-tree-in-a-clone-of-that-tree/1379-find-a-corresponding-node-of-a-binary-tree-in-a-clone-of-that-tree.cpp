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
        if(original -> val == target -> val) {
            return cloned;
        }
        
        queue<TreeNode*> q1, q2;
        q1.push(original);
        q2.push(cloned);
        
        TreeNode* ans = NULL;
        bool flag = false;
        
        while(!q1.empty()) {
            int n = q1.size();
            for(int i = 0; i < n; i++)
            {
                auto p = q1.front();
                auto q = q2.front();
                q1.pop();
                q2.pop();
                if(p -> val == target -> val) {
                    ans = q;
                    flag = true;
                    break;
                }
                if(p -> left) {
                    q1.push(p -> left);
                    q2.push(q -> left);
                }
                if(p -> right) {
                    q1.push(p -> right);
                    q2.push(q -> right);
                }
            }
            if(flag)
                break;
        }
        return ans;
    }
};