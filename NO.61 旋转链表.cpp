/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||k==0)
            return head;
        map<int, ListNode*> Inform;
        ListNode* p = head,*q = head;
        int count = 0;
        p = p->next;
        while(p!=NULL){
            Inform[count] = q;
            q = p;
            p = p->next;
            count ++;
        }
        Inform[count] = q;
        cout<<count<<endl;
        cout<<q->val<<endl;
        q->next = head;
        k = k%(count+1);
        ListNode*t = Inform[(count - k + 1)%(count+1)];
        cout<<t->val<<endl;
        Inform[count - k]->next = NULL;
        return t;
    }
};