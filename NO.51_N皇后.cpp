class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		int i = 0;
		vector<int> temp(n);
		trial(i, n, temp, result);
		return result;
	}
	void trial(const int& i, const int & n, vector<int>& temp, vector<vector<string>>& result) {
		if (i == n) outputstate(temp, result, n);
		else for (int j = 1; j != n + 1; j++) {
			temp[i] = j;
			if (right(temp, i) == true) trial(i + 1, n, temp, result);
			temp[i] = 0;
		}
	}
	bool right(const vector<int>& temp, const int& i) {
			for (int j = 0; j != i; j++) {
				if (temp[i] == temp[j])
					return false;
				else if (((temp[j] - temp[i]) == (j - i))||((temp[j] - temp[i]) == (i - j)))
					return false;
			}
		return true;
	}
	void outputstate(const vector<int>& temp, vector<vector<string>>& result, const int & n) {
		vector<string> temp0;
		for (int i = 0; i != n; i++) {
			string str1(temp[i]-1,'.');
			string str2(n - temp[i], '.');
			string str3 = str1 + "Q";
			string str4 = str3 + str2;
			temp0.push_back(str4);
		}
		result.push_back(temp0);
	}
};