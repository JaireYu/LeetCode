/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//solution1：将每个节点的信息储存在Map关联容器中
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        map<int, ListNode*> Inform;
        ListNode* p = head;
        int count = 0;
        if(head == NULL&&head->next == NULL){
            return NULL;
        }
        while(p!=NULL){
            count++;
            Inform[count] = p;
            p = p->next;
        }
        if(n == count){
            return Inform[2];
        }
        Inform[count - n] -> next = Inform[count - n] -> next -> next;
        return Inform[1];
    }
};