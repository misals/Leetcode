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
    void traverseList(ListNode* head, vector<int> &v) {
        while(head != NULL) {
            v.push_back(head -> val);
            head = head -> next;
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        traverseList(head, v);
        
        int n = v.size();
        stack<int> st;
        vector<int> temp(n);
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= v[i]) {
                st.pop();
            }
            if(st.empty()) {
                temp[i] = -1;
            }
            else {
                temp[i] = st.top();
            }
            st.push(v[i]);
        }
        
        ListNode* ans = NULL;
        ListNode* prev = NULL;
        
        for(int i = 0; i < n; i++) {
            if(temp[i] == -1) {
                if(ans == NULL) {
                    ListNode* node = new ListNode(v[i]);
                    ans = node;
                    prev = node;
                }
                else {
                    ListNode* node = new ListNode(v[i]);
                    prev -> next = node;
                    prev = prev -> next;
                }
            }
        }
        return ans;
    }
};