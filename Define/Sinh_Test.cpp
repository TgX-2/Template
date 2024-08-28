#include <bits/stdc++.h>
using namespace std;
const string name = "test";
const string io   = "temp";
const string trau = "trau";
const int NTEST = 100;


mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

bool bit01() {return Rand(1, 1e5)%2;}
char az() {return (char)(Rand('a', 'z'));}
char AZ() { return (char)(Rand('A', 'Z'));}
char num() {return '0' + Rand(0, 9);}


string bignum(long long l)
{
    string s;
    for(int i = 1; i <= l; i ++)
    {
        s += " ";
        s[s.size() - 1] = num();
    }
    return s;
}

string str(long long a) {
    if(a == 0) return "0";
    if(a < 0) return "-" + str(-a);
    string ans = "";
    for(int i = 1; i <= 4; i ++)
    {
        ans = "0" + ans;
        ans[0] = (a % 10) + '0';
        a /= 10;
    }
    return ans;
}

void sinh() {
}


int main()
{
    srand(time(NULL));
    freopen("result.txt", "w", stdout);
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {

        ofstream inp((io + ".inp").c_str());
        /* Sinh test cho nay */
        inp.close();

        system((name + ".exe").c_str());
        system((trau + ".exe").c_str());

        if (system(("fc " + io + ".out " + io + ".ans").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        } 
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}         
