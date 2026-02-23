class PersistentCHT {
private:
    struct Line {
        int a, b;

        double intersectX(const Line &other) const {
            return (other.b - b) * 1.0 / (a - other.a);
        }

        int eval(const int &x) {
            return a * x + b;
        }
    };

    int top = 0, n;
    vector<Line> hull;
    stack<pair<pair<int, int>, Line>> st;

    void build() {
        hull.resize(n + 7, {0, 0});
    }

    bool isRedundant(const Line &pre, const Line &cur, const Line &nex) {
        return (pre.intersectX(nex) <= pre.intersectX(cur));
    }

    void add_line(const int &a, const int &b) {
        int l = 1, r = top - 1, ans = top;
        Line cur = {a, b};
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (isRedundant(hull[mid - 1], hull[mid], cur)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        st.push({{ans, top}, hull[ans]});
        top = ans + 1;
        hull[ans] = cur;
    }

    int get_query(const int &x) {
        int l = 0, r = top - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if (hull[mid].intersectX(hull[mid + 1]) <= x) l = mid + 1;
            else r = mid;
        }
        return hull[l].eval(x);
    }

    void rollback() {
        assert(!st.empty());
        int pos = st.top().fi.fi;
        top = st.top().fi.se;
        Line cur = st.top().se;
        hull[pos] = cur;
        st.pop();
    }

public: 
    void build(int _n) {
        n = _n;
        build();
    }

    void add(const int &a, const int &b) {
        add_line(a, b);
    }

    int get(const int &x){
        return get_query(x);
    }

    void roll() {
        rollback();
    }
};
