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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *t = head, *node, *list = new ListNode();
        node = list;
        unordered_map<int,int> m;
        for(auto i:nums) m[i]=1;
        while(t) {
            if(!m[t->val]) {
                ListNode *temp = new ListNode(t->val);
                node->next=temp;
                node=node->next;
            }
            t=t->next;
        }
        return list->next;
    }
};