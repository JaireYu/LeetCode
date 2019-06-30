//动态规划法
//步长为i分别截取长度为i的字串，用map来映射是会问去其职位1，可以化归求解
//时间太TM长了吧
class Solution {
public:
	string longestPalindrome(string s) {
		string::size_type n = s.size();
		map<string, int> state;
		string::size_type x = 0;
        string::size_type len = 0;
		int flag[2] = {0,0};
		if (n == 0) {
			return "";
		}
		else if(n > 2){
			for (string::size_type i = 1; i != 3 ; i++) {
				for (string::size_type j = 0; j != n - i + 1; j++){
					string s1(s, j, i);
					if (isturn1(s1)) {
						len = i; x = j;
						state[s1] = 1;
					}
				}
			}
			for (string::size_type i = 3; i != n + 1; i++) {
				if (flag[0] && flag[1]) {
					break;
				}
				int flagtemp = 0;
				for (string::size_type j = 0; j != n - i + 1; j++) {
					string s1(s, j, i);
					if (isturn2(s1, state)) {
						len = i; x = j;
						state[s1] = 1;
						flagtemp = 1;
					}
				}	
				if (flagtemp == 0) {
					flag[i % 2] = 1;
				}
				else {
					flag[(i - 1) % 2] = 0;
				}
			}
			string s1(s, x, len);
			return s1;
		}
		else {
			if (isturn1(s)) {
				return s;
			}
			else{
				string s1;
				return s1 = (1, s[0]);
			}
			
		}

	}
	bool isturn1(const string& s) {
		return equal(s.begin(), s.end(), s.rbegin());
	}
	bool isturn2(const string& s, const map<string, int>& state) {
		string s1(s,1,s.size()-2);
		if (s[0] == s[s.size() - 1] && state.find(s1) != state.end()) {
			return true;
		}
		return false;
	}
};