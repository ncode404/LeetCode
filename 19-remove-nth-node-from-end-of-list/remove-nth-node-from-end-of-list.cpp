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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *t=head;
        while(t) len++,t=t->next;
        len-=n;
        if(!len) return head->next;
        t=head; len--;
        while(len--) t=t->next;
        t->next=t->next->next;
        return head;
    }
};