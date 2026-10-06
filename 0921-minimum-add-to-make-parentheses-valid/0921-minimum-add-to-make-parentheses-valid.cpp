class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int n = s.size();
        int ans = 0;
        stack<int>st;

        for(int i=0 ; i<n ; i++)
        {
            if(st.empty() && s[i] == ')')
            ans++;
            else if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                st.pop();
            }
        }

        return ans+st.size();
        
    }
};