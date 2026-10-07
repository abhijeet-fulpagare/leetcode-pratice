class Solution {
public:
    map<int,set<string>>list;

    void f(string &s,int idx,int d,stack<int>&st,string &temp)
    {
        int n = s.size();
        if(idx >= n)
        {
            if(st.empty())
            {
                list[d].insert(temp);
            }
            return;
        }

        
        temp+=s[idx];
        if(s[idx] == '(')
        {
            st.push(idx);
            f(s,idx+1,d,st,temp);
            st.pop();

            temp.pop_back();
            f(s,idx+1,d+1,st,temp);
        }
        else if(s[idx] == ')'){

            if (st.empty())
            {
                temp.pop_back();
                f(s, idx + 1, d + 1, st, temp);
                return;
            }

            int l = st.top();
            st.pop();
            f(s,idx+1,d,st,temp);
            st.push(l);

            temp.pop_back();
            f(s,idx+1,d+1,st,temp);
        }
        else if(s[idx] >= 'a' && s[idx] <= 'z')
        {
            f(s,idx+1,d,st,temp);
            temp.pop_back();
        }
        
        
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        vector<string> ans;
        stack<int> st;
        string temp;
        f(s, 0, 0, st, temp);

        if (!list.empty())
        {
            ans.assign(list.begin()->second.begin(),
                    list.begin()->second.end());
        }

        return ans;
    }
};