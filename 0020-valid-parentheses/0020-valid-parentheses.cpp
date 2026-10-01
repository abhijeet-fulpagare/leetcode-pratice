class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        int n = s.size();

        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if(s[i] == '"')
            {
                continue;
            }
            else{
                if(s[i] == ')' && !st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else if(s[i] == '}' && !st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else if(s[i] == ']'&& !st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else{
                    return 0;
                }
               
            }
        }

        return st.empty();
    }
};