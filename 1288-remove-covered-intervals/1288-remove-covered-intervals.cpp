struct cmp{
    bool operator()(const vector<int>& a,const vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];   
        return a[0] < b[0];       
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& i) 
    {
        sort(i.begin(), i.end(), cmp());

        int n = i.size();
        int ans = n;

        int a = i[0][0];
        int b = i[0][1];

        for(int j = 1; j < n; j++)
        {
            if(i[j][0] >= a && i[j][1] <= b)
            {
                ans--;
            }
            else
            {
                a = i[j][0];
                b = i[j][1];
            }
        }

        return ans;
    }
};