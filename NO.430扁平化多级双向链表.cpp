/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        flatten_rc(head);
        return head;
    }
    void flatten_rc(Node* &head){
        if(head == NULL) return;
        else if(head->next == NULL){
            if(head->child == NULL)
                return;
            else{
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                flatten_rc(head->next);
                return;
            }
        }
        else{
            Node* p = head;
            Node* q = head->next;
            while(q != NULL){
                if(p->child != NULL){
                    p->next = p->child;
                    p->child->prev = p;
                    p->child = NULL;
                    flatten_rc(p->next);
                    Node* r = p->next;
                    while(r->next != NULL){
                        r = r->next;
                    }
                    r->next = q;
                    q->prev = r;
                }
                p = p->next;
                q = p->next;
            }
            if(p->child != NULL){
                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;
                flatten_rc(p->next);
            }
            return;
        }
        return;
    }
};