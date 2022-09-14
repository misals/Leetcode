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
    void solve(TreeNode* root, map<int, int> &mp, int &cnt) {
        if(root == NULL) {
            return;
        }
        if(root -> left == NULL && root -> right == NULL) {
            mp[root -> val]++;
            int odd = 0;
            for(auto it : mp) {
                if(it.second % 2 != 0)
                    odd++;
                if(odd > 1)
                    break;
            }
            if(odd <= 1)
                cnt++;
            mp[root -> val]--;
            return;
        }
        mp[root -> val]++;
        solve(root -> left, mp, cnt);
        solve(root -> right, mp, cnt);
        mp[root -> val]--;
        
}
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        map<int, int> mp;
        solve(root, mp, cnt);
        
        return cnt;
    }
};