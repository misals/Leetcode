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
    int checkSize(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = checkSize(head);
        ListNode* temp = head;
        int i = 0;
        while(i < n/2) {
            temp = temp -> next;
            i++;
        }
        return temp;
    }
};