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
    ListNode* reverseGroup(ListNode *head, ListNode *end)
    {
        if(!head) return nullptr;
        if(head == end) 
        {
            head->next = nullptr;
            return head;
        }
        ListNode *last = head->next;
        ListNode *tmp = reverseGroup(head->next, end);
        last->next = head;
        head->next = nullptr;
        return tmp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *orig = new ListNode(0, head);
        ListNode *before = orig;
        ListNode *front = head;
        ListNode *end = head;
        while(end)
        {
            int counter = 1;
            while(counter < k && end->next) 
            {
                counter++;
                end = end->next;
            }
            ListNode *after = end?end->next:nullptr;

            if(counter != k) return orig->next;


            ListNode* reversedseg = reverseGroup(front, end);
            ListNode *last = before->next;
            before->next = reversedseg;
            last->next = after;

            before = last;
            front = after;
            end = front;
            after = end?end->next:nullptr;

        }
        return orig->next;
        
    }
};
