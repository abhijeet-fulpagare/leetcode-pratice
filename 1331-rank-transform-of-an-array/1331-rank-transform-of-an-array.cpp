class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    
    {
        int n= arr.size();
        vector<int>temp=arr;

        if(n == 0)
        return {};

        
        sort(temp.begin(),temp.end());

        map<int,int>mp;

        int rank = 1 ;

        for(int i=0 ; i<n-1 ; i++)
        {
            mp[temp[i]] = rank;

            if(temp[i] == temp[i+1])
            continue;

            rank++;
        }
        mp[temp[n-1]] = rank;

        vector<int>ans(n,0);
        for(int i=0 ; i<n ; i++)
        {
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};