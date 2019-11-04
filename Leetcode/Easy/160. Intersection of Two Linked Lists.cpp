// 160. Intersection of Two Linked Lists

// Time Complexity : O(N), Space Complexity : O(1)

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
    
    int getSize(ListNode *head){
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getSize(headA), len2 = getSize(headB);
        ListNode *temp1 = headA, *temp2 = headB;
        
        while(len1 > len2){
            temp1 = temp1->next;
            len1--;
        }
        while(len2 > len1){
            temp2 = temp2->next;
            len2--;
        }
        
        while(temp1 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};