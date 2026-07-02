class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int h) 
    {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>best(n,vector<int>(m,-1));
       
        if(grid[0][0] == 1)
            h--;
        
         q.push({h,{0,0}});


        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            int ht=node.first;
            int r=node.second.first;
            int c=node.second.second;

            if(r == n-1 && c == m-1 && ht>= 1)
            return 1;

            for(auto k:dir)
            {
                int nr=r+k[0];
                int nc=c+k[1];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    int nh = ht - grid[nr][nc];

                    if(nh > 0 && nh > best[nr][nc])
                    {
                        best[nr][nc] = nh;
                        q.push({nh,{nr,nc}});
                    }
                }
            }
        }

        return 0;
        
    }
};