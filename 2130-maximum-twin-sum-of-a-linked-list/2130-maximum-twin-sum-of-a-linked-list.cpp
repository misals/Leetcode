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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(head != NULL) {
            ListNode* nextPtr = head -> next;
            head -> next = prev;
            prev = head;
            head = nextPtr;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = reverseList(slow);
        int ans = 0;
        while(fast != NULL) {
            int val1 = head -> val;
            int val2 = fast -> val;
            
            ans = max(ans, val1 + val2);
            head = head -> next;
            fast = fast -> next;
        }
        return ans;
    }
};