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
    int length(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k, int len) {
        if(len < k) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextPtr = NULL;
        int cnt = 0;
        
        while(curr != NULL && cnt < k) {
            nextPtr = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextPtr;
            cnt++;
        }
        if(nextPtr != NULL) {
            head -> next = reverseKGroup(nextPtr, k, len - k);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = length(head);
        return reverseKGroup(head, k, len);
    }
};