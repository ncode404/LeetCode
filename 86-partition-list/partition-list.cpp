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
    ListNode* partition(ListNode* head, int x) {
        ListNode *L1 = new ListNode(), *L2 = new ListNode(), *t1=L1, *t2=L2;
        ListNode *node = head;
        while(node) {
            if(node->val<x) {
                t1->next = new ListNode(node->val);
                t1=t1->next;
            }
            else {
                t2->next = new ListNode(node->val);
                t2=t2->next;
            }
            node=node->next;
        }
        t1->next = L2->next;
        return L1->next;
    }
};