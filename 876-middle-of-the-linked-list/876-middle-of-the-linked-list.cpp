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
    int findSize(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head -> next;
        }
        return cnt;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = findSize(head);
        
        int i = 0;
        while(i < n/2) {
            head = head -> next;
            i++;
        }
        return head;
    }
};