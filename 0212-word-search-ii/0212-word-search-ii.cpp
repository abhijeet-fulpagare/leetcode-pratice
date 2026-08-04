class trie {
    trie * links[26];
    int flag;
    
    
    public:
    trie()
    {
        flag= 0;
        for(int i=0 ; i<26 ; i++)
        {
            links[i] = NULL;
        }
    }
    
    bool isExist(char c)
    {
        return links[c-'a'] != NULL;
    }
    
    void insert(char c,trie *Node)
    {
        links[c-'a'] = Node;
        return;
    }
    
    trie* next(char c){
        return links[c-'a'];
    }

    void setEnd()
    {
        flag = 1;
    }

    bool getEnd()
    {
        return flag;
    }

    void clearEnd() {
        flag = false;
    }
};

vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int i,int j,trie* root,vector<vector<char>>& board,string &curr, vector<string> &ans)
{
    int n = board.size();
    int m = board[0].size(); 

    char ch = board[i][j];
    

    if (!root->isExist(ch))
        return;

    root = root->next(ch);
    curr.push_back(ch);

    if(root->getEnd())
    {
        ans.push_back(curr);
        root->clearEnd();
    }

    board[i][j] = '$';

    for (auto &k : dir) {
        int nr = i + k[0];
        int nc = j + k[1];

        if (nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] != '$')
            dfs(nr, nc, root, board, curr, ans);
    }

    board[i][j] = ch;
    curr.pop_back();

}

class Solution {
public:


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        int n = words.size();
        trie* root = new trie();

        for(int i = 0 ; i<n ; i++)
        {
            trie *temp = root;
            for(auto c : words[i])
            {
                if(!temp->isExist(c))
                {
                    temp->insert(c,new trie());
                }
                temp = temp -> next(c);
            }
            temp->setEnd();
        }

        vector<string> ans;
        n = board.size();
        int m = board[0].size();

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                trie *temp = root;
                string t;
                dfs(i,j,temp,board,t,ans);
            }
        }

        return ans;
    }
};