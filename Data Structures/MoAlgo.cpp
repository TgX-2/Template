const int maxn = 1e5 + 7;
const int block_sz = 300; // suggest : sqrt(maxn)

struct query {
    int l, r, id;
    bool operator < (const query &other) const {
        int block_a = l / block_sz;
        int block_b = other.l / block_sz;
        if (block_a != block_b) return block_a < block_b;
        return ((block_a & 1) ? (r > other.r) : (r < other.r));
    }
};

vector<query> lqq;
int ans[maxn], anss = 0;

inline void add(int pos) { }
inline void del(int pos) { }


void process() {
    //input add l r id

    sort(all(lqq));

    int l = 0, r = 0;
    for(const query &val : lqq) {
        while(l > val.l) add(--l);
        while(r < val.r) add(++r);
        while(l < val.l) del(l++);
        while(r > val.r) del(r--);
        ans[val.id] = anss;
    }
}