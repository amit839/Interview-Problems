// Link to the problem : https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        for(auto x: lists) if(x) q.push({x->val, x});

        ListNode *head = NULL, *temp = NULL;
        while(!q.empty()){
            auto t = q.top();
            q.pop();

            if(!head) {
                head = temp = t.second;
            }
            else{
                temp->next = t.second;
                temp = temp->next;
            }
            if(t.second->next != NULL){
                q.push({t.second->next->val, t.second->next});
            }
        }
        return head;
    }
};