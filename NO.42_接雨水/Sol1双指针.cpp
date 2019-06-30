typedef vector<int>::iterator iter;
class Solution {
public:
	int trap(vector<int>& height) {
		int rain = 0;
		iter i = height.begin(), j = height.end();
		if (i == j) return 0;
		CulRain(rain, i, j-1, height);
		return rain;
	}
	void CulRain(int &rain, iter i, iter j,const vector<int>& height) {
		if ((j - i) < 2) return;
		iter biggest = max_element(i+1, j);//注意迭代器的结束标志在最后元素之后
		if (*biggest > *i||*biggest > *j) {
			CulRain(rain, i, biggest, height);
			CulRain(rain, biggest, j, height);
		}
		else {
			rain = rain + AddRain(height, i, j);
		}
	}
	int AddRain(const vector<int>& height,iter b,iter e) {
		if (b == e) return 0;
		int add = 0;
		int high = min(*b, *e);
		for (iter i = b + 1; i != e; i++) {
			int vul = high - *i;
			   //整形量不能作为逻辑表达式
		    add = add + vul;
		}
		return add;
	}
};