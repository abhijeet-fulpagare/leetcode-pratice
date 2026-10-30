class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        using State = tuple<int, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty())
        {
            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if(cost != dist[node][cnt])
                continue;

            if(node == n - 1)
                return cost;

            for(auto &[nxt, wt] : adj[node])
            {
                int newCnt;

                if(labels[nxt] == labels[node])
                {
                    newCnt = cnt + 1;
                }
                else
                {
                    newCnt = 1;
                }

                if(newCnt > k)
                    continue;

                int newCost = cost + wt;

                if(newCost < dist[nxt][newCnt])
                {
                    dist[nxt][newCnt] = newCost;
                    pq.push({newCost, nxt, newCnt});
                }
            }
        }

        return -1;
    }
};
