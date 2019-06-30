/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//soulution2 双指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head,*second = head;
        int count = 0;
        if(head == NULL&&head->next == NULL){
            return NULL;
        }
        while(n!=0){
            second = second -> next;
            n--;
        }
        if(second == NULL){
            return head->next;
        }
        while(second->next!=NULL){
            second = second->next;
            first =  first->next;
        }
        first->next = first->next->next;
        return head;
    }
};