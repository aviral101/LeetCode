struct Node{
        Node* ch[26];
        bool flag = false;
        bool present(char c)
        {
            if(ch[c - 'a'] != NULL) return true;
            return false;
        }
        void put(char c, Node* node)
        {
            ch[c - 'a'] = node;
        }
        Node* next(char c)
        {
            return ch[c - 'a'];
        }
    };
class Trie {
private:
    Node* root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i = 0; i<word.size(); i++)
        {
            if(!temp->present(word[i]))
            {
                temp->put(word[i], new Node());
            }
            temp = temp->next(word[i]);
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i = 0; i<word.size(); i++)
        {
            if(!temp->present(word[i])) return false;
            temp = temp->next(word[i]);
        }
        if(temp->flag != true) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i = 0; i<prefix.size(); i++)
        {
            if(!temp->present(prefix[i])) return false;
            temp = temp->next(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */