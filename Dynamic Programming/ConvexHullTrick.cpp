/* 
    Lưu ý:
    - Nếu tìm max: a1 > a2 > a3 > ...
    - Nếu tìm min: a1 < a2 < a3 < ...
*/

struct Line {
    int a, b;
    double intersectX(const Line &other) const {
        return (other.b - b) * 1.0 / (a - other.a);
    }

    int eval(const int &x) const { return (a * x + b); }
};

vector<Line> hull;

bool isRedunant(const Line &pre, const Line &cur, const Line &nex) {
    return (pre.intersectX(nex) <= pre.intersectX(cur));
}

void addLine(const int &a, const int &b) {
    Line cur = {a, b};

    if (!hull.empty() and hull.back().a == a) {
        if (hull.back().b >= b) return;
        else hull.pop_back();
    }

    while((int)(hull.size()) >= 2 and 
        isRedunant(hull[(int)(hull.size()) - 2], hull.back(), cur)) hull.pop_back();
    hull.push_back(cur);
}

int get(const int &x) {
    int l = 1, r = (int)(hull.size()) - 1, ans = 0;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if (hull[mid].intersectX(hull[mid - 1]) <= x) { 
        // Nếu tìm min thì sẽ là <= x
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return hull[ans].eval(x);
}