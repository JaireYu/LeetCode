bool compare(const string& a, const string& b){
            if(a.size()>b.size())
            return true ;
            else if(a.size()<b.size())
                return false;
            else{
                return a<b;
            }
        
    }
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) { 
        bool compare(const string& a, const string& b);
        sort(d.begin(),d.end(),compare);
        typedef vector<string>::const_iterator iter;
        if(d.size() == 0||s == "")return "";
        for(iter i = d.begin(); i != d.end(); i++){
            if(camp(*i, s))
                return *i;
        }
        return "";
    }

    bool camp(const string& s1, const string& s2){
        string::const_iterator i = s1.begin(), j = s2.begin();
        while(j!=s2.end()&&i!=s1.end()){
            if(*i == *j){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == s1.end())
            return true;
        return false;
    }
};