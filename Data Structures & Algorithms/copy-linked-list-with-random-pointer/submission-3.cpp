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
        Node *dummyhead = new Node(0);
        Node *prev = dummyhead;

        //create new nodes, store in m

        while(cp)
        {
            Node *tmp = new Node(cp->val);
            prev->next = tmp;
            prev = tmp;
            m[cp] = tmp;
            cp = cp->next;
        }

        //fill randoms

        cp = dummyhead->next;
        Node *cp2 = head;
        while(cp)
        {
            cp->random = cp2->random? m[cp2->random] : NULL;
            cp2 = cp2->next;
            cp = cp->next;
        }
        return dummyhead->next;
    }
};
