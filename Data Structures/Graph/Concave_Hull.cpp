struct Concave_Hull {
    struct Line {
        int a, b, p;
        bool operator < (const Line &other) { return a < other.a; }
        bool operator < (int x) { return p < x; }
        int eval(int x) { return a * x + b; }
    };

    deque<Line> hull;

    bool isIntersect(Line &x, Line &y) {
        if (x.a == y.a) 
            x.p = (x.b > y.b ? llongmax : llongmin);
        else  
            x.p = (y.b - x.b) /  (x.a - y.a); 

        return (x.p >= y.p);
    }

    void add_line(int a, int b) {
        Line cur_line = {a, b, 0};

        while(len(hull) >= 2 and (isIntersect(cur_line, hull.back()), isIntersect(hull.back(), hull[len(hull) - 2]), cur_line.p < hull.back().p)) 
            hull.pop_back();

        hull.push_back(cur_line);
    }

    int get(int x) {
        while(len(hull) >= 2 and (hull[0].eval(x) >= hull[1].eval(x)))
            hull.pop_front();

        return hull[0].eval(x);
    }
};


/*
How to use :
Concave_Hull name;
name.get(x);
name.add_line(a, b); // a*x + b;
*/
