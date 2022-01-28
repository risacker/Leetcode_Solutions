class WordDictionary {
public:
    class Node{
    public:
    char c;
    vector<Node*> next;
    Node(char cc) {c = cc;}
    };
    
    Node* root;   
  
    WordDictionary() {
    root = new Node(' ');
    }
    
    void addWord(string word) {
        Node* place = root;
        word+=' ';
        for(int i = 0; i < word.size(); i++)
        {
            bool found = false;
            Node* placecopy = place;
            for(int j = 0; j < place->next.size(); j++)
                if(place->next[j]->c == word[i])
                {
                found = true;
                place = place->next[j];
                break;
                }
            
            if(!found)
                {
                Node* newnode = new Node(word[i]);
                place->next.push_back(newnode);
                place = newnode;
                }
        }
        return;
    }
   
    bool search2(string word, Node* root1) {
       if(word.size() == 0) return true;
               Node* place = root1;

    for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == '.')
                {
                    bool match = false;
                    for(int j = 0; j < place->next.size(); j++)
                       if(search2(word.substr(i+1), place->next[j]))
                            return true;
                }
            
            bool found = false;
            for(int j = 0; j < place->next.size(); j++)
                {
                    if(place->next[j]->c == word[i])
                        {
                            found = true;
                            place = place->next[j];
                            break;
                        }
                }
            if(!found)  return false;
            }
      
   return true;
   }
    
    bool search(string word) {
        word+=' '; Node* place = root;
        return search2(word, place); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */