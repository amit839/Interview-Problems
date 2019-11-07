//  https://leetcode.com/problems/delete-node-in-a-linked-list/

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
    void deleteNode(ListNode* node) {
        ListNode *previous = NULL, *current = node;
        while(current->next){
            current->val = current->next->val;
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
    }
};