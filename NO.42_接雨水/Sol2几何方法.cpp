class Solution {    //思路来自Leetcode友人
public: int trap(vector<int>& height) {
    
    int sum_rain = 0;  //雨水量
	int max_height = 0;
	int n_height = height.size();

	for (int i = 0; i < n_height; i++)
	{
		if (height[i] > max_height) {
			max_height = height[i];
	 }
	}

	int sum_area = max_height * n_height;
	int light_area = 0;
	int stone_area = 0;

	//左边阳光照射
	for (int i = 0; i < max_height; i++)
	{
		int n = 0;

		while (n<n_height && (max_height - i) > height[n]) 
        {

			light_area++;
			n++;
			
		}

	}

	//右边阳光照射
	for (int i = 0; i < max_height; i++) {

		int n = n_height - 1;
		while (n >= 0 && (max_height - i) > height[n])
		{
			light_area++;
			n--;
		}

	}

	//计算原始的数组面积,相当于求围"水坝的石头面积"
	for (int i = 0; i < n_height; i++)
	{
		stone_area += height[i];
	}


	sum_rain = sum_area - light_area - stone_area;

	return sum_rain;}
};