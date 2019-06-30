class Solution {
public:
	bool checkInclusion(string s1, string s2) {
        string::size_type n=s1.size(), m= s2.size();
		if (n == 0)
			return false;
		if (m < n)
			return false;
		vector<int> s10 = { 0 ,0,0,0,0,0,0,0,0,0,0,0,0,
			                0 ,0,0,0,0,0,0,0,0,0,0,0,0 };
		string::size_type i, j;
		for (i = 0; i != n; i++) {
			s10[s1[i] - 'a']++;
		}
		i = 0;
		j = n;
		while (j != m) {
			if (compare(s10, i, j, s2))
				return true;
			i++; j++;
		}
		if (compare(s10, i, j, s2))
			return true;
		return false;
	}
    bool compare(vector<int> s10, string::size_type& i, string::size_type& j, string& s2){
        string::size_type h;
        for(h = i; h!=j; h++){
            if(s2[h]>'z'||s2[h]<'a')
                return false;
            if(s10[s2[h]-'a']==0)
                return false;
            else
                s10[s2[h]-'a']--;
        }
        return true;
    }
};