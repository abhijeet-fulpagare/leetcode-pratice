class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        int a1=0,a2=0;

        for(int i=0 ; i<n-1 ; i++)
        {
            if(arr[i] == arr[i+1])
            {
                ans=max(ans,a1);
                ans=max(ans,a2);
                a1=a2=0;
                continue;
            }

            if( arr[i] > arr[i+1] )
            {
                ans=max(a2,ans);
                a1++;
                a2=0;
            }
            if(arr[i] < arr[i+1] )
            {
                ans=max(a1,ans);
                a2++;
                a1=0;
            }
        }

        ans=max(ans,a1);
        ans=max(ans,a2);
        return ans+1;
    }
};