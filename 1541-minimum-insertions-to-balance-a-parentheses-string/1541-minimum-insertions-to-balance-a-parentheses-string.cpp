class Solution {
public:
    int minInsertions(string s) 
    {
        int n = s.size();
        int ans = 0;
        stack<int>st;

        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {   
                if(st.empty())
                {
                    if(i+1 < n && s[i+1] == ')')
                    {
                        ans++;
                        i = i+1;
                    }
                    else{
                        ans+=2;
                    }
                }
                else{
                    st.pop();

                    if(i+1 < n && s[i+1] == ')')
                    {
                        i=i+1;
                    }
                    else{
                        ans+=1;
                    }
                }
            }
        }

        while(!st.empty())
        {
            ans+=2;
            st.pop();
        }

        return ans;
        
    }
};