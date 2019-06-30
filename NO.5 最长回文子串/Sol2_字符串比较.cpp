typedef struct {
	string::size_type x, y;
	string::size_type len = 0;
} Inform;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) {
			return "";
		}
		Inform In1,In2;
		const string::size_type n = s.size() + 1;
		char ** Mode = new char*[n];
		Mode[0] = new char[n];
		for (string::size_type i = 1; i != n; i++) {
			Mode[i] = new char[n];
			Mode[i][0] = s[i - 1];
		}
		for (string::size_type i = 1; i != n; i++) {
			Mode[0][i] = s[i - 1];
		}
		for (string::size_type j = 1; j != n; j++) {
			for (string::size_type i = n - j; i != n; i++) {
				if (s[i - 1] == s[n - j - 1])
					Mode[i][j] = '1';
				else
					Mode[i][j] = '0';
			}
		}
		for (string::size_type i = 1; i != n; i++) {
			if (Mode[i][n - i] == '1') {
				GetInform(i, In1, Mode, n, 0);
			}
		}
		for (string::size_type i = 2; i != n; i++) {
			if (Mode[i][n - i + 1] == '1') {
				GetInform(i, In2, Mode, n, 1);
			}
		}
		for (string::size_type i = 1; i != n; i++) {
			delete[] Mode[i];
		}
		delete Mode;
		if ((2*In1.len-1) > 2*In2.len) { 
			string s1(s, In1.x - In1.len, 2 * In1.len - 1);
			return s1;
		}
		else {
			string s1(s, In2.x - In2.len-1, 2 * In2.len);
			return s1;
		}
	}
	void GetInform(const string::size_type& i, Inform& In, char** Mode, const int& n,int flag) {
		string::size_type len = 0;
		string::size_type k = i,h = n-i+flag;
		while (k != n&&h != n &&Mode[k][h] == '1') {
			k++;
			h++;
			len++;
		}
		if (len > In.len) {
			In.len = len;
			In.x = i;
			In.y = n-i+flag;
		}
		return;
	}
};