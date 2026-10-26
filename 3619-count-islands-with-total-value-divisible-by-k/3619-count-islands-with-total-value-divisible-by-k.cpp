class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int &k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        long long sum = grid[i][j];

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(auto l : dir)
            {
                int nr = l[0] + r;
                int nc = l[1] + c;

                if(nc >=0 && nc<m && nr >=0 && nr < n && grid[nr][nc] != 0 && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    sum+=grid[nr][nc];
                    q.push({nr,nc});
                }
            }
        }

        if((sum % k) == 0)
        return 1;

        return 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] != 0 && !vis[i][j])
                {
                    ans+=f(i,j,grid,vis,k);
                }
            }
        }
        return ans;
    }
};