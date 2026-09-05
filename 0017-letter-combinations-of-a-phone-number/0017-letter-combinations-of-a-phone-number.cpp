class Solution {
public:
    
    void f(int ind,string &dig,vector<string>&adj,vector<string>&ans,string &tp)
    {
        int n = dig.size();

        if(ind >= n)
        {
            ans.push_back(tp);
            return;
        }

        int d = dig[ind]-'0';
        string temp = adj[d-2];


        for(auto i:temp)
        {
            tp+=i;
            f(ind+1,dig,adj,ans,tp);
            tp.pop_back();
        }
    }
    vector<string> letterCombinations(string dig) 
    {
        vector<string>adj={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;
        string k="";
        f(0,dig,adj,ans,k);
        return ans;
        
       



        
    }
};