class Solution {
public:

    bool check_valid(int mid,vector<vector<pair<long long,long long>>>&adj,vector<bool>& online,long long k)
    {
        int n=online.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0});

        while (!pq.empty())
        {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            if (node == n - 1) return true;

            for (auto [v, wt] : adj[node])
            {
                if (!online[v] || wt < mid) continue;

                long long newCost = cost + wt;

                if (newCost <= k && newCost < dist[v])
                {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        return 0;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) 
    {

        int low=INT_MAX;
        int high=0;
        long long n=online.size();

        vector<vector<pair<long long,long long>>>adj(n);


        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            low=min(low,i[2]);
            high=max(high,i[2]);
        }

        if(online[n-1] == 0 || online[0] == 0)
        return -1;

        
        int ans=-1;
        while(low <= high)
        {
            int mid=low+(high-low)/2;

            if(check_valid(mid,adj,online,k))
            {
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }

        

        return ans;
    }
};