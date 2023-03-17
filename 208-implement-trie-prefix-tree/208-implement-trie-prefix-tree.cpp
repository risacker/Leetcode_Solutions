class TrieNode{
    public:
    bool endOfWord;
    TrieNode* children[26];          //use array,better memory usage
    
    TrieNode()
    {
        endOfWord = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;   
        }
    }
};





class Trie {
public:

    Trie() {
        root = new TrieNode();
    }

    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }
            
            curr = curr->children[index];
        }
        
        curr->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                      //not even reached at end of the word
            }
            
            
        }
        
        return curr->endOfWord; //reached end of word, now endOfWord will decide whether such word exists that end at this curr position
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(int i = 0; i<prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                    //if not even reached till end of prefix, so false
            }
        }
        return true;
        
    }
    
    
//---------------------------------------------------------------------------------------------------------------------    
        
    ~Trie(){                         //destructor: to free memory
        clear(root);
    }
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }

private:  //GOOD PRACTICE TO KEEP ROOT NODE PRIVATE
    TrieNode* root;
    

};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */