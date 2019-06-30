class Solution {
public:
    int maxArea(vector<int>& height) {
        int b,e;
        b = 0;e = height.size()-1;
        int area = 0;
        while(b!=e){
            area = max(min(height[b],height[e])*(e-b),area);
            if(height[b]>height[e])
                e--;
            else
                b++;
        }
        return area;
    }
};