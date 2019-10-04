// link to the problem statement : https://leetcode.com/contest/weekly-contest-151/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    
    bool checkarr(vector<int>& arr){
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i ; j < n; j++){
                sum += arr[j];
                if(sum == 0){
                    arr.erase(arr.begin() + i, arr.begin() + j + 1);
                    return false;
                }
            }
        }
        return true;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        while(1){
            if(checkarr(arr)) break;
        }
        if(arr.size() == 0) return NULL;
        
        head = temp = NULL;
        for(auto x: arr){
            ListNode *ad = new ListNode(x);
            if(head == NULL){
                head = temp = ad;
            }
            else {
                temp->next = ad;
                temp = temp->next;
            }
        }
        return head;
    }
};