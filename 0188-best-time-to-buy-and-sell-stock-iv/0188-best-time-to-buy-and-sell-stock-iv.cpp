class Solution {
public:

    int f(int ind ,int buy ,int cap ,vector<int>& p,vector<vector<vector<int>>>&dp)
    {
        int n=p.size();


        if(ind == n)
        return 0;

        if(cap == 0)
        return 0;

        if(dp[ind][buy][cap] != -1)
        return  dp[ind][buy][cap];

        int p1 = 0;
        if(buy)
        {
            p1 = -p[ind] + f(ind+1,0,cap,p,dp);
        }
        else{
            p1 = p[ind] + f(ind+1,1,cap-1,p,dp);
        }

        int p2 = f(ind+1,buy,cap,p,dp);

        return dp[ind][buy][cap] = max(p1,p2);
    }
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i = n-1 ; i>= 0 ; i--)
        {
            for(int j=0 ; j<=1 ; j++)
            {
                for(int l = 1 ; l<=k ; l++)
                {
                    int p1 = 0;
                    if(j)
                    {
                        p1 = -prices[i] + dp[i+1][0][l];
                    }
                    else{
                        p1 = prices[i] + dp[i+1][1][l-1];
                    }

                    int p2 = dp[i+1][j][l];

                    dp[i][j][l] = max(p1,p2);
                }
            }
        }

        return dp[0][1][k];
    }
};