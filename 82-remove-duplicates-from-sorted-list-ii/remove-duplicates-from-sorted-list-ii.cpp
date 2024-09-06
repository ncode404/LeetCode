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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return 0;

        unordered_map<int,int> m;
        ListNode *node, *list = new ListNode(), *tmp=head;
        node=list;
        while(tmp) {
            if((tmp->next && tmp->val!=tmp->next->val) && !m[tmp->val]) {
                node->next=new ListNode(tmp->val);
                node=node->next;
            }
            m[tmp->val]++;
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp->next) tmp=tmp->next;
        // cout<<tmp->val<<" ";
        if(m[tmp->val]==1) node->next=new ListNode(tmp->val);
        return list->next;
    }
};