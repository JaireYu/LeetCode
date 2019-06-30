//首先造图，将始末节点包含在内
//BFS广度优先搜索，直到找到末节点

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int n = wordList.size() + 1;
		int e;
		for (e = 0; e != n - 1; e++) {
			if (endWord.compare(wordList[e]) == 0)
				break;
		}
		if (e == n - 1)
			return 0;
		vector<int> visit(n);
		queue<int> Q;
		vector<vector<int>> vec = init(beginWord, endWord, wordList);
		visit[0] = 1;
		Q.push(0);
		int lenth = 1;
		while (!Q.empty()) {
			int Qlength = Q.size();
			for (int i = 0; i < Qlength; i++) {
				int temp = Q.front();
				Q.pop();
				for (int i = 0; i != vec[temp].size(); i++) {
					if (visit[vec[temp][i]] == 0) {
						if (vec[temp][i] == e + 1)
							return lenth + 1;
						else {
							visit[vec[temp][i]] = 1;
							Q.push(vec[temp][i]);
						}
					}
				}
			}
			lenth++;
		}
		return 0;
	}
	vector<vector<int>> init(string& beginWord, string& endWord, vector<string>& wordList) {
		vector<vector<int>> vec;
		int n = wordList.size();
		vector<int> temp;
		for (int i = 0; i != n; i++) {
			if (compare(wordList[i], beginWord) == true) {
				temp.push_back(i + 1);
			}
		}
		vec.push_back(temp);
		for (int i = 0; i != n; i++) {
			vector<int> temp;
			if (compare(beginWord, wordList[i])) {
				temp.push_back(0);
			}
			for (int j = 0; j != i; j++) {
				if (compare(wordList[i], wordList[j]) == true) {
					temp.push_back(j + 1);
				}
			}
			for (int j = i + 1; j != n; j++) {
				if (compare(wordList[i], wordList[j]) == true) {
					temp.push_back(j + 1);
				}
			}
			vec.push_back(temp);
		}
		return vec;
	}
	bool compare(const string& str1, const string& str2) {
		int n = str1.size();
		int flag = 0;
		for (int i = 0; i != n; i++) {
			if (str1[i] != str2[i]) {
				if (flag == 1)
					return false;
				else
					flag = 1;
			}
		}
		if (flag == 0) {
			return false;
		}
		return true;
	}
};