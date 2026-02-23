bool isCCW(const pair<int, int> &a,
           const pair<int, int> &b,
           const pair<int, int> &c) {
    return ((b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi)) > 0;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

vector<pair<int, int>> hull;
void ConvexHull() {
    hull.pb(point[0]);

    FOR(i, 1, n - 1) {
        while(len(hull) >= 2 and 
            isCCW(hull[len(hull) - 2], hull.back(), point[i])) {
            hull.pop_back();
        }

        hull.pb(point[i]);
    }

    FORD(i, n - 2, 0) {
        while(len(hull) >= 2 and 
            isCCW(hull[len(hull) - 2], hull.back(), point[i])) {
            hull.pop_back();
        }

        hull.pb(point[i]);
    }

    if (n > 1) hull.pop_back();
}

/*
Code trong ham main:

sort(all(point), cmp);
ConvexHull();
*/