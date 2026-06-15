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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto cmpfunc = [](ListNode *a, ListNode *b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmpfunc)> minheap(cmpfunc);
        for(ListNode* l: lists)
        {
            if(l) minheap.push(l);
        }
        ListNode *res = new ListNode(0);
        ListNode *curr = res;
        while(!minheap.empty())
        {
            ListNode *node = minheap.top();
            minheap.pop();
            curr->next = node;
            curr = node;
            node = node->next;
            if(node) minheap.push(node);
        }
        return res->next;
    }
};
