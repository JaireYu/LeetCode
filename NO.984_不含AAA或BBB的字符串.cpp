class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s;
        int flag1 = 1, flag2 = 1;
        while(A!=0&&B!=0){
            if(flag1 == 1&&flag2 == 1){
                if(A==2*(B+1)){
                    s.push_back('a');
                    s.push_back('a');
                    A = A-2;
                    flag1 = 0;
                }
                else if(B == 2*(A+1)){
                     s.push_back('b');
                    s.push_back('b');
                    B = B-2;
                    flag2 = 0;
                }
                else if(B>=A){
                    s.push_back('b');
                    B--;
                    flag2 = 0;
                }
                else{
                    s.push_back('a');
                    A--;
                    flag1 = 0;
                }
            }
            else if(flag1 == 1){
                if(A == 2*(B+1)){
                    s.push_back('a');
                    s.push_back('a');
                    A = A-2;
                    flag1 = 0;
                    flag2 = 1;
                }
                else{
                    s.push_back('a');
                    A--;
                    flag1 = 0;
                    flag2 = 1;
                }
            }
            else if(flag2 == 1){
                if(B == 2*(A+1)){
                    s.push_back('b');
                    s.push_back('b');
                    B = B-2;
                    flag2 = 0;
                    flag1 = 1;
                }
                else{
                    s.push_back('b');
                    B--;
                    flag2 = 0;
                    flag1 = 1;
                }
            }
            else{
                return "error";
            }
        }
        while(A>0){
            s.push_back('a');
            A--;
        }
        while(B>0){
            s.push_back('b');
            B--;
        }
        return s;
    }
};