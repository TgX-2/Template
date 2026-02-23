/* Author : naot */

struct Node;
Node* newNode(int l, int r);
Node* newNode(Node* cur);
 
struct Node {
    int l, r;
    ll sum = 0;
    Node *left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int l, int r): l(l), r(r) {}
    Node(Node* cur): l(cur->l), r(cur->r), sum(cur->sum), left(cur->left), right(cur->right) {}
 
    bool isLeaf() {
        return l == r;
    }
 
    void summonChild() {
        int mid = (l + r) >> 1;
        left = newNode(l, mid);
        right = newNode(mid+1, r);
    }
 
    void updateSum() {
        sum = left->sum + right->sum;
    }
 
    bool notIntersect(int a, int b) {
        return r < a || l > b;
    }
 
    bool inRange(int a, int b) {
        return l >= a && r <= b;
    }
};
 
Node nodes[N]; // suggest 4 * maxn * const
int cntNodes = 0;
 
Node* newNode(int l, int r) {
    nodes[cntNodes] = Node(l, r);
    return &nodes[cntNodes++];
}
 
Node* newNode(Node* cur) {
    nodes[cntNodes] = Node(cur);
    return &nodes[cntNodes++];
}
 
struct Segtree {
    vector<Node*> roots;
 
    void build(Node* cur, int a[]) {
        if(cur->isLeaf()) {
            cur->sum = a[cur->l];
            return;
        }
 
        cur->summonChild();
 
        build(cur->left, a);
        build(cur->right, a);
 
        cur->updateSum();
    }
 
    void build(int n, int a[]) {
        roots.push_back(newNode(1, n));
        build(roots.back(), a);
    }
 
    Node* update(Node* cur, int a, int x) {
        if(cur->notIntersect(a, a)) return cur;
 
        Node* newCur = newNode(cur);
        if(cur->isLeaf()) {
            newCur->sum = x;
            return newCur;
        }
 
        newCur->left = update(cur->left, a, x);
        newCur->right = update(cur->right, a, x);
 
        newCur->updateSum();
 
        return newCur;
    }
 
    void update(int k, int a, int x) {
        k--;
        roots[k] = update(roots[k], a, x);
    }
 
    ll get(Node* cur, int a, int b) {
        if(cur->notIntersect(a, b)) return 0;
        if(cur->inRange(a, b)) return cur->sum;
 
        return get(cur->left, a, b) + get(cur->right, a, b);
    }
 
    long long get(int k, int a, int b) {
        k--;
        return get(roots[k], a, b);
    }
 
    void copy(int k) {
        k--;
        roots.push_back(roots[k]);
    }
};


/* How to use 
  SegTree seg; 
  
  seg.build(n, a); 
  // n : size, a : array value

  seg.update(k, pos, val);
  // k : time, pos : position, val : value

  seg.get(k, l, r);
  // k : time, get sum l -> r

   seg.copy(k);
   // k : time
  
*/
