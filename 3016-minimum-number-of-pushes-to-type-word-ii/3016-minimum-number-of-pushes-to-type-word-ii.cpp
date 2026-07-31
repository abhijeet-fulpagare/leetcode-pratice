class Solution {
public:
    int minimumPushes(string word) 
    {
        int n = word.size();
        vector<int>freq(26,0);


        for(int i=0 ; i<n ; i++)
        {
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>() );

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            ans += freq[i] * (i / 8 + 1);
        }



        return ans;
    }
};