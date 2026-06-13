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
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode *copy = new ListNode(0, head);
        ListNode *frontcopy = head;
        ListNode *backcopy = copy;
        while(n>0)
        {
           frontcopy = frontcopy->next;
           n--;
        }
        while(frontcopy)
        {   
            frontcopy = frontcopy->next;
            backcopy = backcopy->next;
        }

        backcopy->next = backcopy->next->next;
        return copy->next;

        // 1 2 3 4 : 2
    }
};
