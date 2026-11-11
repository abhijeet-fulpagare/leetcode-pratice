class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) 
    {
        if (need1 < need2)
            return minimumCost(cost2, cost1, costBoth, need2, need1);

        long long ans = 0;

        ans += 1LL * need2 * min(costBoth, cost1 + cost2);

        ans += 1LL * (need1 - need2) * min(cost1, costBoth);

        return min(ans, 1LL * max(need1, need2) * costBoth);

    }
};