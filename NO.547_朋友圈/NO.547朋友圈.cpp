#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int N = M.size();
		vector<int> friendset(N);
		for (int i = 0; i != N; i++) {
			friendset[i] = i;
		}
		vector<int> friendset_size(N, 1);
		int count = N;
		for (int i = 0; i != N; i++) {
			for (int j = 0; j != i; j++) {
				if (M[i][j] == 1) {
					merge(i, j, friendset, friendset_size, count);
				}
			}
		}
		return count;
	}
	int find(int a, vector<int> &friendset) {
		int af = friendset[a];
		while (af != a) {
			a = af;
			af = friendset[a];
		}
		return a;
	}
	void merge(int a, int b, vector<int> &friendset, vector<int> &friendset_size, int &N) {
		int af = find(a, friendset);
		int bf = find(b, friendset);
		if (bf == af)
			return;
		else if (friendset_size[bf] < friendset_size[af]) {
			friendset[bf] = af;
			friendset_size[af] += friendset_size[bf];
		}
		else {
			friendset[af] = bf;
			friendset_size[bf] += friendset_size[af];
		}
		N--;
	}
};
int main() {
	vector<vector<int>> friends = { 
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, 
	{0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0}, 
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0}, 
	{0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1}, 
	{0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0}, 
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1} };
	cout << Solution().findCircleNum(friends);
	system("pause");
}