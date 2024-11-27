/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using   namespace std;

#define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
#define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)

#define fi                 first
#define se                 second
#define pb                 push_back
#define len(x)             (int)((x).size())
#define all(x)             (x).begin(), (x).end()

#define _                  << " " <<
#define __                 << "\n"
#define ___                << " "

#define ______________TgX______________ main()
#define int                long long
#define intmax             1e9
#define intmin            -1e9
#define llongmax           1e18
#define llongmin          -1e18

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout << endl; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << "[ " << *it << " = " << a << " ] ";
    err(++it, args...);
}

template<typename T1, typename T2> ostream& operator << (ostream& out, const pair<T1, T2>& p) {
    return out << "[ " << p.first << " , " << p.second << " ] ";
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator << (ostream& out, const Con& con) {
    for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
        out << *it << " ";
    }
    return out << "";
}
/*-----------------------------*/

int getint(int l, int r) {
    int res = 0;
    for(int i = 0; i <= 3; i++) 
        res = (res << 15) ^ (rand() & ((1 << 15) - 1));
    return l + rand() % (r - l + 1);
}

vector<int> getarr(int n, int l, int r) {
    vector<int> a(n);
    for(int &x : a) 
        x = getint(l, r);
    return a;
}

vector<int> getpermutation(int n) {
    vector<int> a(n);
    iota(all(a), 1);
    random_shuffle(all(a));
    return a;
}


/*-----------------------------*/
______________TgX______________ {
    srand(time(NULL));
    freopen("result.txt", "w", stderr);
    for(int itest = 1; itest <= 1000; itest++) {
        ofstream inp("temp.inp");

        inp.close();

        system("temp.exe");
        system("temp_trau.exe");
        if (system("fc temp.ans temp.out") != 0) {
            cerr << "Test " << itest << ": Wrong!"; 
            return 0;
        }
        cerr << "Test " << itest << ": Right!" << "\n"; 
        cerr << "---------------\n";
    }
}

