class Node{
    Node* links[26];
    int flag;

    public:
    Node()
    {
        flag = 0;
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool ifNotNodeCharExists(char c)
    {
        return (links[c - 'a'] == NULL);
    }

    void insertNode(char c,Node* newNode)
    {
        links[c-'a'] = newNode;
    }

    Node* getNodeAtChar(char c)
    {
        Node* temp = links[c-'a'];

        return temp;
    }

    void setEnd()
    {
        flag =1;
        return;
    }

    bool checkFlag()
    {
        return (flag == 1);
    }
};

class Trie {

private: Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* temp = root;
        int n = word.size();
        for(int i=0 ; i<n ; i++)
        {
            if(temp->ifNotNodeCharExists(word[i]))
            {
                temp->insertNode(word[i],new Node());
            }

            temp = temp->getNodeAtChar(word[i]);
        }

        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;

        int n = word.size();

        for(int i=0 ; i<n ; i++)
        {
            if(temp->ifNotNodeCharExists(word[i]) == 0)
            {
                temp = temp->getNodeAtChar(word[i]);
            }
            else{
                return 0;
            }
        }

        return temp->checkFlag();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        int n = prefix.size();

        for(int i=0 ; i<n ; i++)
        {
            if(temp->ifNotNodeCharExists(prefix[i]) == 0)
            {
                temp = temp->getNodeAtChar(prefix[i]);
            }
            else{
                return 0;
            }
        }

        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */