class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string::size_type i, j;
		string::size_type record = 0;
		for (i = 0; i != s.size(); i++) {
			for (j = i ; j != s.size(); j++) {
				string s1(s,i, j-i);
				if (compare(s1, j, s))
					record = max(record, j + 1 - i);
				else
					break;
			}
		}
		return record;
	}
	bool compare(string s1, string::size_type j, string s) {
		string::size_type i;
		for (i = 0; i != s1.size(); i++) {
			if (s1[i] == s[j]) return false;
		}
		return true;
	}
};