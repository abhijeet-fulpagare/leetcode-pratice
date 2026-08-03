class Solution {
public:

    int f(int idx,int pick,vector<int>& st,vector<vector<int>>&dp)
    {
        int n = st.size();

        if(idx >= n)
        return 0;

        if(dp[idx][pick] != -1)
        return dp[idx][pick];

        
        if(pick == 0)
        {
            int ans = INT_MIN;
            int temp =0;
            for(int i= idx ; i<n && i< idx+3; i++)
            {
                temp += st[i];

                ans = max(ans,temp + f(i+1,1,st,dp));
            }

            return dp[idx][pick] = ans;
        }

        int ans = INT_MAX;
        int temp =0;
        for(int i= idx ; i<n  && i < idx+3; i++)
        {
            temp -= st[i];

            ans = min(ans,temp + f(i+1,0,st,dp));
        }

        return dp[idx][pick] = ans;
        

    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int x = f(0,0,stoneValue,dp);

        if(x < 0)
        return "Bob";
        else if(x > 0)
        return "Alice";

        return "Tie";
    }
};