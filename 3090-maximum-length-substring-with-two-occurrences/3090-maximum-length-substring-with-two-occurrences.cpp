class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        vector<int>freq(26,0);
        int  n = s.size();

        int cnt = 0;
        int ans = 0;
        int l = 0;
        for(int i=0 ; i<n ; i++)
        {
            freq[s[i]-'a']++;
            cnt++;

            while(freq[s[i]-'a'] > 2)
            {
                freq[s[l]-'a']--;
                l++;
                cnt--;
            }

            ans = max(cnt,ans);
        }

        return ans;
        
    }
};