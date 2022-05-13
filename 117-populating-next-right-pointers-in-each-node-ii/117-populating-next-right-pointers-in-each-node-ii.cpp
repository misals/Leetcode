/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void populate(Node* root) {
        if(root == NULL) {
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                if(temp -> left != NULL) {
                    q.push(temp -> left);
                }
                if(temp -> right != NULL) {
                    q.push(temp -> right);
                }
                if(i == n - 1) {
                    temp -> next = NULL;
                } else {
                    auto currNext = q.front();
                    temp -> next = currNext;
                }
            }
        }
    }
    
    Node* connect(Node* root) {
        populate(root);
        return root;
    }
};