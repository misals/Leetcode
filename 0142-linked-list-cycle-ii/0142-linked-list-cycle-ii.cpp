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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }
        int i = 0;
        map<ListNode*, int> mp;
        while(head != NULL) {
            if(mp.find(head) != mp.end()) {
                return head;
            }
            mp[head] = i;
            head = head -> next;
            i++;
        }
        return NULL;
        
    }
};