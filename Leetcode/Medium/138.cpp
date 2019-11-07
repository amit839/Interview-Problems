// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *start = head;
        
        while(start){
            Node *add_node = new Node(start->val);
            mp[start] = add_node;
            start = start->next;
        }
        start = head;
        while(start){
            mp[start]->next = start->next ? mp[start->next] : NULL;
            mp[start]->random = start->random ? mp[start->random] : NULL;
            start = start->next;
        }
        return mp[head];
    }
};