class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0}};

    bool f(int i, int j, vector<vector<char>>& grid, int cnt,
           vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[i][j] == '(')
            cnt++;
        else
            cnt--;

        if(cnt < 0)
            return false;

        if(dp[i][j][cnt] != -1)
            return dp[i][j][cnt];

        if(i == n-1 && j == m-1)
            return dp[i][j][cnt] = (cnt == 0);

        bool ans = false;

        for(auto k : dir) {
            int nr = i + k[0];
            int nc = j + k[1];

            if(nr < n && nc < m)
                ans |= f(nr, nc, grid, cnt, dp);
        }

        return dp[i][j][cnt] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if((n + m - 1) % 2 != 0)
            return false;

        if(grid[0][0] == ')')
            return false;

        if(grid[n-1][m-1] == '(')
            return false;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(n + m, -1))
        );

        return f(0, 0, grid, 0, dp);
    }
};