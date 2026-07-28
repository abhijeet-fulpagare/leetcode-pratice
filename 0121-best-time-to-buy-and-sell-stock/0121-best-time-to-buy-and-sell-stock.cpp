class Solution {
public:

    
    int maxProfit(vector<int>& p) {
        int mini = p[0];
        int n = p.size();
        int profit = 0;
        for(int i=1 ;i<n ; i++)
        {
            int prof = p[i] - mini;
            profit = max(profit, prof);
            mini =min (mini,p[i]);
        }

        return profit;
    }
};