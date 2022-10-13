/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void traverse(ListNode* node) {
        while(node != NULL) {
            v.push_back(node -> val);
            node = node -> next;
        }
    }
    
    void deleteNode(ListNode* node) {
        traverse(node);
        int n = v.size();
        
        ListNode* prev = node;
        
        for(int i = 1; i < n; i++) {
            node -> val = v[i];
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
    }
};