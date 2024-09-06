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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        
        ListNode *tmp=head;
        int n=0, c=0;
        while(tmp) {
            n++; tmp=tmp->next;
        }
        tmp=head;
        ListNode *node1, *list1 = new ListNode(), *node2, *list2 = new ListNode();
        node1=list1; node2=list2;
        k%=n;
        while(tmp) {
            if(c<n-k) {
                node1->next=new ListNode(tmp->val);
                node1=node1->next;
            }
            else {
                node2->next=new ListNode(tmp->val);
                node2=node2->next;
            }
            tmp=tmp->next;
            c++;
        }
        node2->next=list1->next;
        return list2->next;
    }
};