class ConvexHullTrick {
private:
    struct Line {
        int a, b;
        double intersectX(const Line &other) const { return (other.b - b) * 1.0 / (a - other.a); }
        int eval(const int &x) const { return (a * x + b); }
    };

    vector<Line> hull;

    bool isRedunant(const Line &pre, const Line &cur, const Line &nex) {
        return (pre.intersectX(nex) <= pre.intersectX(cur));
    }

    void add_line(const int &a, const int &b) {
        Line cur = {a, b};
        while (len(hull) >= 2 and isRedunant(hull[len(hull) - 2], hull.back(), cur)) hull.pop_back();
        hull.pb(cur);
    }

    int get_query(const int &x) {
        int l = 1, r = len(hull) - 1, ans = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (hull[mid].intersectX(hull[mid - 1]) <= x) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;;
        }

        return hull[ans].eval(x);
    }
public:
    void add(const int &a, const int &b) {
        add_line(a, b);
    }

    int get(const int &x) {
        return get_query(x);
    }
};
