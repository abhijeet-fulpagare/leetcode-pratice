class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        queue<pair<int,int>> q;

        vector<int> best(n + 1, -1);

        q.push({INT_MAX, 1});
        best[1] = INT_MAX;

        int ans = INT_MAX;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int score = t.first;
            int node = t.second;

            ans = min(ans, score);

            for (auto &i : adj[node]) {
                int v = i.first;
                int wt = i.second;

                int newScore = min(score, wt);

                if (best[v] == -1 || newScore < best[v]) {
                    best[v] = newScore;
                    q.push({newScore, v});
                }
            }
        }

        return ans;
    }
};