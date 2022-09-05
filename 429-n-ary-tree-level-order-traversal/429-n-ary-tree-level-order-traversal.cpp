/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                auto currNode = q.front();
                q.pop();
                
                temp.push_back(currNode -> val);
                
                for(int j = 0; j < currNode -> children.size(); j++) {
                    q.push(currNode -> children[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};