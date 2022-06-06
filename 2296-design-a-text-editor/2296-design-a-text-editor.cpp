class TextEditor {
public:
    string bef, aft;
    TextEditor(){
        bef = "";
        aft = "";
    }
    
    void addText(string text){
        bef += text;
    }
    
    int deleteText(int k){
        int minm = min(int(bef.length()), k);
        for(int i = 0; i < minm; ++i) 
            bef.pop_back();
        return minm;
    }
    string cursorLeft(int k){
        int minm = min(k, int(bef.length()));
        for(int i = 0; i < minm; ++i) {
            aft.push_back(bef.back());
            bef.pop_back();
        } 
        int maxlen = min(10, int(bef.length()));
        return bef.substr(bef.length() - maxlen);
    }
    
    string cursorRight(int k) {
        int minm = min(k, int(aft.length()));
        for(int i = 0; i < minm; ++i) {
            bef.push_back(aft.back());
            aft.pop_back();
        }    
        int maxlen = min(10, int(bef.length()));     
        return bef.substr(bef.length() - maxlen);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */