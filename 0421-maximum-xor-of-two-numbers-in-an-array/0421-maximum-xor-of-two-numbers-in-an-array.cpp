
class trie{

    trie* links[2];

    public:
    trie()
    {
        links[0] = links[1] = NULL;
    }

    bool isExists(bool c)
    {
        return (links[c] != NULL);
    }

    void insert(bool c,trie* Node)
    {
        links[c] = Node;
        return;
    }

    trie* next(bool c)
    {
        return links[c];
    }

};
class Solution {
    trie *root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new trie();
        int n=nums.size();
        for(int j= 0 ; j<n ; j++)
        {
            int no = nums[j];
            trie *temp = root;

            for(int i=31 ; i >= 0 ; i--)
            {
                bool k = ((no >> i) & 1);
                if(!temp->isExists(k))
                {
                    temp->insert(k,new trie());
                }

                temp = temp->next(k);
            }
        }

        int ans = 0;
        for(int j=0 ; j<n ; j++)
        {
            int no = nums[j];
            trie *temp = root;

            int curr = 0;

            for(int i=31 ; i >= 0 ; i--)
            {
                bool k = ((no >> i) & 1);

                if(temp->isExists(!k))
                {
                    curr = (curr | (1<<i));
                    temp = temp->next(!k);
                }
                else{
                    temp = temp->next(k);
                }
                
            }

            ans= max(ans,curr);
        }

        return ans;
    }
};