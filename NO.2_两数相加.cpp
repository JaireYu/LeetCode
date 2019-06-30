/*struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		struct ListNode* p = l1, *q = l2, *l3 = NULL;
		vector<int> v3;
		int temp = 0;
		while (p!=NULL&&q!=NULL) {
			int sum = p->val + q->val;
			v3.push_back((sum + temp)%10);
			temp = (temp + sum) / 10;
			p = p->next, q = q->next;
		}
		if (p == nullptr) {
			while(q){
				v3.push_back((temp + q->val) % 10);
				temp = (temp + q->val) / 10;
				q = q->next;
			}
		}
		else {
			while (p) {
				v3.push_back((temp + p->val) % 10);
				temp = (temp + p->val) / 10;
				p = p->next;
			}
		}
		if (temp != 0) {
			v3.push_back(temp);
		}
		vector<int>::size_type i = v3.size();
		l3 = (ListNode *)malloc(sizeof(ListNode));
		l3->val = v3[i-1];
		l3->next = NULL;
		i--;
		while(i){
			p = (ListNode *)malloc(sizeof(ListNode));
			p->val = v3[i-1];
			p->next = l3;
			l3 = p;
			i--;
		}
		return l3;
	}
};