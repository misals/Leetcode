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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* intersectionNode = NULL;
        
        while(headA != NULL) {
            ListNode* temp = headB;
            bool flag = false;
            while(temp != NULL) {
                if(headA == temp) {
                    intersectionNode = headA;
                    flag = true;
                    break;
                }
                temp = temp -> next;
            }
            if(flag) {
                break;
            }
            headA = headA -> next;
        }
        return intersectionNode;
    }
};