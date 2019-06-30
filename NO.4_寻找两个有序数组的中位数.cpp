class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
		vector<int>::size_type iter1 = 0, iter2 = 0;
		while (iter1 != nums1.size() && iter2 != nums2.size()) {
			if (nums1[iter1] < nums2[iter2]) {
				nums3.push_back(nums1[iter1]);
				iter1++;
			}
			else {
				nums3.push_back(nums2[iter2]);
				iter2++;
			}
		}
		if (iter1 == nums1.size()) {
			while (iter2 != nums2.size()) {
				nums3.push_back(nums2[iter2]);
				iter2++;
			}
		}
		else {
			while (iter1 != nums1.size()) {
				nums3.push_back(nums1[iter1]);
				iter1++;
			}
		}
		return get_median(nums3, 0, nums3.size()-1);
	}
	double get_median(vector<int>& nums3, vector<int>::size_type i, vector<int>::size_type j) {
		if ((j - i) == 1) return double(nums3[i] + nums3[j]) / 2.0;
		else if (j == i) return double(nums3[i]);
		else
		{
			i++;
			j--; return get_median(nums3, i, j);
		}
	}
};