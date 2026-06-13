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
    ListNode *reverseSegment(ListNode *head, ListNode *end)
    {
        if(head == end)
        {
            head->next = NULL;
            return head;
        }
        ListNode *temp = reverseSegment(head->next, end);
        ListNode *cp = temp;
        while(cp->next) cp = cp->next;
        head->next = NULL;
        cp->next = head;
        return temp;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *leftptr = dummyhead;
        ListNode *rightptr = head;
        for(int i = 0; i < right - left; i++) rightptr = rightptr->next;
        for(int i = 1; i < left; i++)
        {
            leftptr = leftptr->next;
            rightptr = rightptr->next;
        }
        ListNode *before = leftptr;
        leftptr = leftptr->next;
        ListNode *after = rightptr->next;
        ListNode *reversedSegment = reverseSegment(leftptr, rightptr);
        before->next = reversedSegment;
        ListNode *cp = reversedSegment;
        while(cp->next)
        {
            cp = cp->next;
        } 
        cp->next = after;
        return dummyhead == before? dummyhead->next : head;
        
    }
};