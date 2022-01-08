void insertSorted(stack<int> &s, int t) {
    if (s.empty() || t >= s.top()) {
        s.push(t);
        return;
    }
    
    int e = s.top();
    s.pop();
    insertSorted(s, t);
    s.push(e);
}

void SortedStack :: sort() {
    if (s.empty()) {
        return;
    }
    
    int t = s.top();
    s.pop();
    sort();
    
    insertSorted(s, t);
}
