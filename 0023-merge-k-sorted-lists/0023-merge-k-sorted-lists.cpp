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
    struct myCmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, myCmp> pq;
        int n = lists.size();
        
        for(int i = 0; i < n; i++) {
            auto node = lists[i];
            if(node != NULL) {
                 pq.push(node);
            }
        }
        ListNode* head = NULL;
        ListNode* temp = NULL;
     
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            if(head == NULL) {
                head = node;
                temp = node;
            }
            else {
                temp -> next = node;
                temp = temp -> next;
            }
            if(node != NULL && node -> next != NULL) {
                pq.push(node -> next);
            }
        }
       //temp -> next = NULL;
        return head;
    }
};