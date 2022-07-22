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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        
        small -> next = head;
        large -> next = head;
        
        ListNode* smallitr = small;
        ListNode* largeitr = large;
        
        while(head != NULL) {
            if(head -> val < x) {
                small -> next = head;
                small = small -> next;
            }
            else {
                large -> next = head;
                large = large -> next;
            }
            head = head -> next;
        }
        large -> next = NULL;
        small -> next = largeitr -> next;
        return smallitr -> next;
        
    }
};