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
    void recursion(ListNode *&head,int k,int nodes,int &total,int &b) {
        if(!head) {
            total=nodes; return;
        }
        recursion(head->next,k,nodes+1,total,b);
        if(nodes==(total-k-1)) {
            if(head->next) {
                head->next=head->next->next;
                b=1;
            }
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *copy = head;
        int total=0,b=0;
        recursion(copy,n,1,total,b);
        if(!b) head=head->next;
        return head;
    }
};