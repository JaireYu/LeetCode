#define max_len 115
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0'||num2[0] == '0')
            return "0";
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> num10(max_len);
        vector<int> num20(max_len);
        vector<int> num_res(2*max_len-1);
        string res;
        for(int i = max_len - len1; i != max_len; i++){
            num10[i] = int(num1[i - max_len + len1]) - '0';
        }
        for(int i = max_len - len2; i != max_len; i++){
            num20[i] = int(num2[i - max_len + len2]) - '0';
        }
        for(int i = max_len - 1; i != max_len - 1 - len1; i--){
            for(int j = max_len - 1; j != max_len - 1 - len2 ; j--){
                num_res[i + j] += num10[i] * num20[j];
            }
        }
        bool start = false;
        for(int i = 2*max_len - 2; i != 0; i--){
            num_res[i - 1] += num_res[i]/10;
            num_res[i] %= 10;
        }
        for(int i = 0; i != 2*max_len - 1; i++){
            if(num_res[i] != 0){
                res.push_back('0' + num_res[i]);
                start = true;
            }
            else if(start)
                res.push_back('0' + num_res[i]);
        }
        return res;
    }
};