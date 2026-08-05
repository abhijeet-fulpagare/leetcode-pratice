class Solution {
public:

    void dfs(int node,vector<int>&buged,vector<vector<int>>&adj)
    {
        buged[node] = 1;

        for(auto i:adj[node])
        {
            if(!buged[i])
            {
                dfs(i,buged,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);

        for(auto i:invocations)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }


        vector<int>buged(n,0);

        dfs(k, buged, adj);

        bool ok = true;

        for (auto &e : invocations)
        {
            if (!buged[e[0]] && buged[e[1]])
            {
                ok = false;
                break;
            }
        }

        vector<int> ans;

        if (ok)
        {
            for (int i = 0; i < n; i++)
                if (!buged[i])
                    ans.push_back(i);
        }
        else
        {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        }

        return ans;
    }
};