class Solution {
public:

    vector<vector<int>>dir{{-1,0,-1},{0,-1,0},{-1,0,0},{0,-1,-1}};
    vector<vector<vector<int>>> dp;
    int calSum(vector<vector<int>>& grid,int r1,int c1,int r2)
    {

        int n=grid.size();
        int m=grid[0].size();

        int c2 = r1 + c1 - r2;

        

        if(r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0)
            return -1e9;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];


        if((r1 == 0 && c1 ==0) && r2 == 0 )
        {
            return grid[0][0] ;
        }

        int ans=-1e9;
        for(auto i:dir)
        {
            int nr1 = i[0]+r1;
            int nc1 = i[1]+c1;
            int nr2 = i[2]+r2;

            int nc2 = nr1+nc1 - nr2;

            if(nr1 >= 0 && nr1 < n && nc1 >= 0 && nc1 < m &&
            nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < m && 
            grid[nr1][nc1] != -1 && grid[nr2][nc2] != -1)
            {
                int temp = calSum(grid,nr1,nc1,nr2) ;

                if(temp == -1e9)
                continue;

                if(r1 == r2 && c1 == c2)
                    ans = max(ans, temp + grid[r1][c1]);
                else
                    ans = max(ans, temp + grid[r1][c1] + grid[r2][c2]);
            }
        }
        
        return dp[r1][c1][r2] =ans;

    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();

        dp.assign(n, vector<vector<int>>(n, vector<int>(m, -1)));
        int a =calSum(grid,n-1,m-1,n-1);
        

        if(a == -1e9)
        return 0;

        return a;

        
        
    }
};