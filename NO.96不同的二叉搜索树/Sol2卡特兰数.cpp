class Solution {
public:
	int numTrees(int n) {
        if(n == 0)return 1;
		double count = 1;
        for(int i = 1; i <= n; i ++){
            count = count*double(n+i)/double(i);
        }
        return int(count/(n+1));
	}
};