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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = NULL;
        ListNode* prev = head;
        bool flag = true;
        
        while(head != NULL) {
            if(head -> val == val) {
                ListNode* temp = head;
                while(temp != NULL && temp -> val == val) {
                    temp = temp -> next;
                }
                prev -> next = temp;
            }
            if(head -> val != val && flag) {
                flag = false;
                ans = head;
            }
            
            prev = head;
            head = head -> next;
        }
        
        return ans;
    }
};