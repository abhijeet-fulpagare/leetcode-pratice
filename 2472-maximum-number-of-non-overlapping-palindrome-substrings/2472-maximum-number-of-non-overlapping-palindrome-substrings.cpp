class Solution {
public: 

    bool isp(string &temp,int i,int n)
    {
        while(i <= n)
        {
            if(temp[i++] != temp[n--])
            return 0;
        }

        return 1;
    }
    int f(string &s, int &k,int st,int e,vector<vector<int>>&dp)
    {
        int n = s.size();

        if(e >= n)
        return 0;

        if(dp[st][e] != -1)
        return dp[st][e];

        if(e-st+1 < k)
        return dp[st][e] = max(f(s,k,st,e+1,dp),f(s,k,st+1,e+1,dp));

        if(isp(s,st,e))
        {
            return dp[st][e]  = 1+f(s,k,e+1,e+1,dp);
        }
        
        return dp[st][e]=f(s,k,st,e+1,dp);

        
    }
    int maxPalindromes(string s, int k) {
        
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(s,k,0,0,dp);
        
    }
};