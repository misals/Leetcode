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
    ListNode* findMid(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        
        while(head != NULL) {
            ListNode* nextPtr = head -> next;
            head -> next = prev;
            prev = head;
            head = nextPtr;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return;
        }
        ListNode* mid = findMid(head);
        ListNode* R = reverseList(mid);
        ListNode* L = head -> next;
        
        for(int i = 0; L != R; i++, head = head -> next) {
            if(i & 1) {
                head -> next = L;
                L = L -> next;
            }
            else {
                head -> next = R;
                R = R -> next;
            }
        }
        
        
        
    }
};