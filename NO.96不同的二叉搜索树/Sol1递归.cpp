class Solution {
public:
	int numTrees(int n) {
		return countTree(n);
	}
	int countTree(const int& n) {
		if (n == 0) return 1;
		int count = 0;
		for (int i = 0; i < n/2; i++)
			count = count + 2*countTree(i - 0)*countTree(n - i - 1);
        if(n%2 == 0) return count;
        else{
            count = count + countTree(n/2)*countTree(n/2);
            return count;
        }
		
	}
};