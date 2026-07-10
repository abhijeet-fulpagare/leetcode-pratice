class Solution {
public:

    int f(int n ,int m,vector<vector<int>>&dp)
    {
        if(n == 0 && m == 0)
        return 1;

        if(n<0 || m<0)
        return 0;

        if(dp[n][m] != -1)
        return dp[n][m];

        int u=0,l=0;
        if(n-1 >= 0)
        {
            u=f(n-1,m,dp);
        }

        if(m-1 >= 0)
        {
            l=f(n,m-1,dp);
        }

        return dp[n][m]=l+u;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        dp[0][0]=1;
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if( i == 0 && j == 0)
                continue;

                int u=0,l=0;
                if(j-1 >= 0)
                {
                    u=dp[i][j-1];
                }

                if(i -1 >= 0)
                {
                    l=dp[i-1][j];
                }

                dp[i][j]=u+l;
            }
        }

        return dp[m-1][n-1];
    }
};