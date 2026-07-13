class Solution {
public:

    int f(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(n  < 0 || m < 0)
        return 1e9;

        if(n == 0 && m == 0)
        {
            return grid[0][0];
        }

        if(dp[n][m] != -1)
        return dp[n][m];


        int l=1e9,r=1e9;
        if(n-1 >= 0)
          l=f(n-1,m,grid,dp);
        
        if(m-1 >= 0)
        {
            r=f(n,m-1,grid,dp);
        }

        return dp[n][m]=min(l,r)+grid[n][m];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));

        // return f(n-1,m-1,grid,dp);
        
        dp[0][0]=grid[0][0];

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(i == 0 && j == 0)
                continue;

                int l=1e9,r=1e9;

                if(i-1 >= 0)
                    l=dp[i-1][j];
                
                if(j-1 >= 0)
                {
                    r=dp[i][j-1];
                }


                dp[i][j] = min(l,r)+grid[i][j];
            }
        }


        return dp[n-1][m-1];

        
    }
};