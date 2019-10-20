#include<iostream>
#include<vector>
using namespace std;
//ע��HEAPIFY�����ı߽������������ȵ�������˳��������������ѭ�������±�ջ
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		BUILD_MAX_HEAP(nums);
		return find_k_large(nums, k);
	}
	inline int left(int i) { //i ��index
		return (2 * (i+1) - 1);
	}
	inline int right(int i) { //i ��index
		return 2 * (i+1);
	}
	int parent(int i) {
		if (i % 2 == 0) { //i ��ż��
			return (i - 2) / 2;
		}
		else {  //i ������
			return (i - 1) / 2;
		}
	}
 	void MAX_HEAPIFY(vector<int>& nums, int i) {
		int length = nums.size();
		int largest = i;
		if (left(i) < length) {
			if(nums[left(i)] > nums[largest])
				largest = left(i);
		}
		else {
			return;
		}
		if (right(i) < length) {
			if(nums[right(i)] > nums[largest])
				largest = right(i);
		}
		if (largest == i)
			return;
		int temp = nums[largest];
		nums[largest] = nums[i];
		nums[i] = temp;
		MAX_HEAPIFY(nums, largest);
	}
	void BUILD_MAX_HEAP(vector<int>& nums) {
		int length = nums.size() - 1;
		while (length >= 0) {
			MAX_HEAPIFY(nums, length);
			length--;
		}
	}
	int find_k_large(vector<int>& nums, int k) {
		if (k == 1) {
			return nums[0];
		}
		else {
			int length = nums.size() - 1;
			int temp = nums[length];
			nums[length] = nums[0];
			nums[0] = temp;
			nums.erase(nums.end() - 1);
			MAX_HEAPIFY(nums, 0);
			return find_k_large(nums, k - 1);
		}
	}
};
int main() {
	vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	cout<<(Solution().findKthLargest(nums, 4));
	system("pause");
}