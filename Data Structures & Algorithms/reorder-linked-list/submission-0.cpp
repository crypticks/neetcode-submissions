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
private:
    ListNode* reverseList(ListNode *head)
    {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *temp = reverseList(head->next);
        ListNode *cp = temp;
        while(cp->next) cp = cp->next;
        head->next = NULL;
        cp->next = head;
        return temp;
    }

public:
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        while(temp)
        {
            temp->next = reverseList(temp->next);
            temp = temp->next;
        }
    }
};
