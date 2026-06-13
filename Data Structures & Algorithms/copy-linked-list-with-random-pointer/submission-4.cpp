/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node *cp = head;
        while(cp)
        {
            m[cp] = new Node(cp->val);
            cp = cp->next;
        }
        cp = head;
        while(cp)
        {
            Node *curr = m[cp];
            curr->next = m[cp->next];
            curr->random = m[cp->random];
            cp = cp->next;
        }
        return m[head];
    }
};
