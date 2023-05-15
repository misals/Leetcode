/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        for(int i = 0; i < k - 1; i++) {
            temp1 = temp1 -> next;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp -> next;
        }
        for(int i = 0; i < n - k; i++) {
            temp2 = temp2 -> next;
        }
        swap(temp1 -> val, temp2 -> val);
        
        return head;
    }
};