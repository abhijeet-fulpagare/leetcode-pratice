class Solution {
public:

    vector<vector<int>>dir1={{1,-1},{1,0},{1,1}};
    

    int dp[71][71][71];
    int f(int r1,int c1,int c2,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];

        

        if(r1 == n-1)
        {
            
            if(c1 == c2)
            return grid[r1][c1];

            return grid[r1][c1]+grid[r1][c2];
        }

        int ans=0;
        for(auto i:dir1)
        {
            int nr1 = r1+i[0];
            int nc1 = c1+i[1];
            
                
            for(int j=-1 ; j<=1 ; j++)
            {
                int nc2 = c2+j;

                if(nr1 < n && nc1 < m && nc1 >= 0 && nr1 >= 0 &&
                 nc2 >= 0 &&  nc2 < m
                )
                {
                    ans=max(ans,f(nr1,nc1,nc2,grid));
                }
            }
        }

        if(c1 == c2)
        return dp[r1][c1][c2]=ans+grid[r1][c1];

        return dp[r1][c1][c2]=ans+grid[r1][c1]+grid[r1][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        int m=grid[0].size();
        return f(0,0,m-1,grid);        
    }
};