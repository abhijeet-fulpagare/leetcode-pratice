class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int ans = INT_MAX;

        vector<int> best(n, INT_MAX);

        int l = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            while (sum > target)
            {
                sum -= arr[l];
                l++;
            }

            if (sum == target)
            {
                int len = i - l + 1;

                if (l > 0 && best[l - 1] != INT_MAX)
                {
                    ans = min(ans, len + best[l - 1]);
                }

                if (i == 0)
                    best[i] = len;
                else
                    best[i] = min(best[i - 1], len);
            }
            else
            {
                if (i > 0)
                    best[i] = best[i - 1];
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};