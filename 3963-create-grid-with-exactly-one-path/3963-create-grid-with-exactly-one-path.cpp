class Solution {
public:
    vector<string> createGrid(int m, int n) 
    {
        vector<string>ans(m);

        for(int i=0 ; i<m ; i++)
        {
            string t;

            if(i == 0)
            {
                for(int j =0 ;j<n ; j++)
                {
                    t+='.';
                }
            }
            else{
                for(int j =0 ;j<n ; j++)
                {
                    if(j == n-1)
                    {
                        t+='.';
                        continue;
                    }
                    t+='#';
                }
            }
            ans[i] = t;
        }

        return ans;


        
    }
};