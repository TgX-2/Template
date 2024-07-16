struct Trie {
    struct Node {
        int child[27];
        int exist, cnt;
    } node[26 * maxn];
    int cur;
 
    void add(string s) {
        int pos = 0;
        for(auto x : s) {
            int c = x - 'a';
            if(!node[pos].child[c]) node[pos].child[c] = ++cur;
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }
 
    bool find(string s) {
        int pos = 0;
        for(auto x : s) {
            int c = x - 'a';
            if(!node[pos].child[c]) return 0;
            pos = node[pos].child[c];
        }
        return (node[pos].exist != 0);	
    }
    
    bool delete_resc(int pos, string &s, int i) {
        if (i != len(s)) {
            int c = s[i] - 'a';
            bool is = delete_resc(node[pos].child[c], s, i + 1);
            if (is) node[pos].child[c] = -1;
        } else node[pos].exist--;

        if (pos != 0) {
            node[pos].cnt--;
            if (node[pos].cnt == 0) return 1;
        } else return 0;
    }

    void delele(string s) {
        if (find(s) == 0) return;
        delete_resc(0, s, 0);
    }

} trie;
