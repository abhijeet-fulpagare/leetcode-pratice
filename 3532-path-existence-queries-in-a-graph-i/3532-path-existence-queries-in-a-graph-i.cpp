class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) 
    {
        vector<bool>ans;

        vector<int>t(n,0);

        for(int i=0 ; i<n-1 ; i++)
        {
            if((nums[i+1] - nums[i]) > maxDiff)
            t[i]=1;
        }

        vector<int>prefix(n+1,0);
        for(int i=1 ; i<=n ; i++)
        {
            prefix[i]=prefix[i-1]+t[i-1];
        }


        for(auto i:q)
        {

            
            int s=min(i[0],i[1]);
            int e=max(i[0],i[1]);

            if(prefix[s] == prefix[e])
            {
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }

        }

        return ans;
        
    }
};