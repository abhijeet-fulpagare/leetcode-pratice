class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        int flag = 1;
        if(i == 0 || i == n-1 || j == 0 || j == m-1)
        {
            flag = 0;
        }

        vis[i][j] = 1;

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(auto k:dir)
            {
                int nr = r + k[0];
                int nc = c + k[1];

                if(nr >= 0 && nr < n && nc>=0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});

                    if(nr == 0 || nr == n-1 || nc == 0 || nc == m-1)
                    {
                        flag = 0;
                    }
                }
            }
        }

        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] == 0 && !vis[i][j])
                {
                    ans+=f(grid,i,j,vis);
                }
            }
        }
        
        return ans;
    }
};