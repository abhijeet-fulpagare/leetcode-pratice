class Solution {
public:
    
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> distance(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    distance[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(auto &k : dir)
            {
                int nr = r + k[0];
                int nc = c + k[1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc])
                {
                    distance[nr][nc] = distance[r][c] + 1;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                vis[i][j] = 0;

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({distance[0][0], {0,0}});

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int dist = node.first;
            int r = node.second.first;
            int c = node.second.second;

            if(vis[r][c]) continue;
            vis[r][c] = 1;

            if(r == n-1 && c == m-1)
                return dist;

            for(auto &k : dir)
            {
                int nr = r + k[0];
                int nc = c + k[1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc])
                {
                    int newd = distance[nr][nc];
                    pq.push({min(dist,newd), {nr,nc}});
                }
            }
        }

        return -1;
    }
};