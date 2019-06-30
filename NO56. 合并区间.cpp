#include<algothrim>
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		int n = intervals.size();
        if(n == 0)
            return {};
		sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res = Merge(intervals);
		return res;
	}
	/*void Qsort(vector<Interval>& intervals, int l, int h) {
		if (l >= h) return;
		int mid = Sort(intervals, l, h);
		Qsort(intervals, l, mid - 1);
		Qsort(intervals, mid + 1, h);
	}
	int Sort(vector<Interval>& intervals, int l, int h) {
		if (l == h - 1 && intervals[l].start > intervals[h].start)
			return l;
		int temp = intervals[l].start;
		int i = l + 1;
		int j = h;
		while (i < j) {
			while (i <= h&&intervals[i].start >= temp) {
				i++;
			}
			while (j >= 0&&intervals[j].start < temp) {
				j--;
			}
			if(i < j)
			    swap(intervals[i], intervals[j]);
		}
		swap(intervals[j], intervals[l]);
		return j;
	}*/
    vector<Interval> Merge(vector<Interval>& inter){
        vector<Interval> res;
        int len = inter.size();
        if(len != 0){
            res.push_back(inter[len-1]);
            inter.pop_back();
        }
        len = len - 1;
        while(len != 0){
            Interval temp = inter[len - 1];
            inter.pop_back();
            Interval temp0 = res[res.size() - 1];
            if(havetomerge(temp, temp0)){
                res.pop_back();
                Interval temp1 = Interval(temp0.start, max(temp.end, temp0.end));
                res.push_back(temp1);
            }
            else
                res.push_back(temp);
            len = inter.size();
        }
        return res;
    }
    bool havetomerge(const Interval& a, const Interval& b){
        if(a.start <= b.end)
            return true;
        else
            return false;
    }
    static bool compare( Interval a,  Interval b){
        return a.start>b.start;
    }
};