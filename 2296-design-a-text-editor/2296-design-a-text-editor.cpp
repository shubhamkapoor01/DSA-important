class TextEditor {
    string before;
    string after;
    
public:
    TextEditor() {
    }
    
    void addText(string text) {
        before += text;
    }
    
    int deleteText(int k) {
        int deleted = 0;
        while(before.size() && k --) {
            before.pop_back();
            deleted ++;
        }
        return deleted;
    }
    
    string cursorLeft(int k) {
        while (before.size() && k --) {
            char ch = before.back();
            after.push_back(ch);
            before.pop_back();
        }
        int len = min((int)before.size(), 10);
        return before.substr(before.size() - len);
    }
    
    string cursorRight(int k) {
        while (after.size() && k --) {
            char ch = after.back();
            before.push_back(ch);
            after.pop_back();
        }
        int len = min((int)before.size(), 10);
        return before.substr(before.size() - len);
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