class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        stack<int> st;
        int n = tokens.size();
        for(int i = 0; i != n; i++){
           if(tokens[i] == "+"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v1 + v2);
            }
            else if(tokens[i] == "-"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v2 - v1);
            }
            else if(tokens[i] == "*"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v1 * v2);
            }
            else if(tokens[i] == "/"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                st.push(v2 / v1);
            }
            else
                st.push(atoi(tokens[i].c_str()));
        }
        return st.top();
    }
};