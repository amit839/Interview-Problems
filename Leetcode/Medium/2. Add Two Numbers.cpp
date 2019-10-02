// Link to the problem : https://leetcode.com/problems/add-two-numbers/

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
    int getLen(ListNode* l){
        int ct = 0;
        while(l){
            ct++;
            l = l->next;
        }
        return ct;
    }
    ListNode* addList(ListNode* l1, ListNode* l2){
        ListNode* temp = l1;
        int carry = 0;
        while(temp and l2){
            int val = temp->val + l2->val + carry;
            carry = val > 9 ? 1 : 0;
            temp->val = val % 10;
            if(carry and temp->next == NULL){
                temp->next = new ListNode(1);
                return l1;
            }
            temp = temp->next;
            l2 = l2->next;
        }
        while(temp and carry){
            int val = temp->val + carry;
            carry = val > 9 ? 1 : 0;
            temp->val = val % 10;
            if(carry and temp->next == NULL){
                temp->next = new ListNode(1);
                return l1;
            }
            temp = temp->next;
        }
        
        return l1;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = getLen(l1), m = getLen(l2);
        if(n > m){
            return addList(l1, l2);   
        }
        else{
            return addList(l2, l1);
        }
    }
};