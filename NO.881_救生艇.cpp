class Solution {    //双指针
public:
    int numRescueBoats(vector<int>& people, int limit) {
        typedef vector<int>::const_iterator iter;
        int count = 0;
        sort(people.begin(),people.end());
        iter st = people.begin(), en = people.end()-1;
        while((en-st)>0){
            if((*st+*en)<=limit){
                count ++;
                st++;
                en--;
            }
            else{
                en--;
                count++;
            }
        }
        if(en == st){
            count++;
        }
        return count;
    }
};