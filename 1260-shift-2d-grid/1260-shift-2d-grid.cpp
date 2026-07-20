class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m= grid[0].size();

        int size = n*m ;

        k = k % (n*m);


        if( k == 0)
        return grid;

        while(k-- > 0)
        {   
            vector<int>temp;
            for(int i=0 ; i<n ; i++)
            {
                temp.push_back(grid[i][m-1]);
                for(int j=m-1 ; j>=1 ; j--)
                {
                    grid[i][j] = grid[i][j-1];
                }

            }

            
            grid[0][0] = temp[n-1];

            for(int i=1 ; i<n ; i++)
            {
                grid[i][0] = temp[i-1];
            }
        }

        return grid;
        
    }
};