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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        int n = lists.size();
        
        for(int i = 0; i < n; i++) {
            auto head = lists[i];
            while(head != NULL) {
                ans.push_back(head -> val);
                head = head -> next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode* head = NULL;
        ListNode* temp = NULL;
        
        int sz = ans.size();
        
        if(sz == 0) return NULL;
        
        for(int i = 0; i < sz; i++) {
            if(head == NULL) {
                ListNode* node = new ListNode(ans[i]);
                head = node;
                temp = node;
            }
            else {
                ListNode* node = new ListNode(ans[i]);
                temp -> next = node;
                temp = temp -> next;
            }
        }
        temp -> next = NULL;
        return head;
    }
};