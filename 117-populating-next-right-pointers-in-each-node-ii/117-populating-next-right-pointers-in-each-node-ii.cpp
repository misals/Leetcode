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
    Node* connect(Node* root) {
        Node* head = root;
        if(root == NULL) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
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
                if(i == n - 1) {
                    node -> next = NULL;
                } else {
                    auto temp = q.front();
                    node -> next = temp;
                }
            }
        }
        return head;
    }
};