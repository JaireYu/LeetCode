class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == NULL)
            return {};
        vector<string> res;
        map<int, string> MAP;
        MAP[2] = string("abc");
        MAP[3] = string("def");
        MAP[4] = string("ghi");
        MAP[5] = string("jkl");
        MAP[6] = string("mno");
        MAP[7] = string("pqrs");
        MAP[8] = string("tuv");
        MAP[9] = string("wxyz");
        string temp = "";
        int count = 0;
        int len = digits.size();
        BFS(res, count, temp, len, MAP, digits);
        return res;
    }
    void BFS(vector<string>& res, int count, string temp, const int& len, map<int, string>& MAP, const string& digits){
        if(count == len){
            res.push_back(temp);
            return;
        }
        else
            for(int i = 0; i!=MAP[digits[count] - '0'].size(); i++){
                temp.push_back(MAP[digits[count] - '0'][i]);
                BFS(res, count + 1, temp, len, MAP, digits);
                temp.pop_back();
            }
        return;
    }
};