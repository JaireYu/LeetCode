//三路快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, equal = 0, end = nums.size()-1;//用int型的可以容纳-1，end就可以取到-1，方便了条件判断
           if(end>0){
            while(start<=end){   //等号一定要加，否则最后st，end都指向0时，就结束了，少了一个元素的处理
                if(nums[start]==0){
                    swap(nums[equal], nums[start]);
                    equal ++,start ++;
                }
                else if(nums[start] == 1){
                    start ++;
                }
                else{
                    swap(nums[start], nums[end]);
                    end--;
                }
            }
        }
    }
};