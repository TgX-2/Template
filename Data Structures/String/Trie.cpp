struct Trie {
    struct Node {
        int child[30];
        int exist, cnt;
    } nodes[10000];

    int cur;


    void add(const string &s) {
        int pos = 0;

        for(const char &x : s) {
            int c = x - 'a';
            if (nodes[pos].child[c] == 0) {
                cur++;
                nodes[pos].child[c] = cur;
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool find(const string &s) {
        int pos = 0;

        for(const char &x : s) {
            int c = x - 'a';
            if (nodes[pos].child[c] == 0) return 0;
            pos = nodes[pos].child[c];
        }

        return (nodes[pos].exist != 0);
    }

    bool dele(int pos, const string &s, int i) {
        if (i != len(s)) {
            int c = s[i] - 'a';
            bool is = dele(nodes[pos].child[c], s, i + 1);
            if (is) nodes[pos].child[c] = 0;
        } else nodes[pos].exist--;

        if (pos != 0) {
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return 1;
        } else return 0;
    }

    void del(const string &s) {
        if (find(s) == 0) return;
        dele(0, s, 0);
    }


    Trie() : cur(0) {
        memset(nodes[0].child, 0, sizeof(nodes[0].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };
};
