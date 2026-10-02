class Solution {
public:

    void f(int n , vector<string>&ans , string temp,int op)
    {
        if(n == 0 )
        {
            if(op == 0)
                ans.push_back(temp);
            return;
        }

        if(op > 0)
        {
            temp+=')';
            f(n-1,ans,temp,op-1);
            temp.pop_back();
        }

        temp+='(';
        f(n-1,ans,temp,op+1);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        int op = 0;
        f(n*2,ans,"",op);

        return ans;
    }
};