#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define pll pair<ll , ll>
#define lp(i, j, n) for (int i = j; i <= n; i++)
#define vi vector<int>
#define popcnt(a) __builtin_popcount(a)
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define vpl vector<pll>
#define veclp(n) for(auto it=n.begin() ; it!=n.end();it++)
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX (1<<8)
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18
#define cond(flag) if(flag)cout<<"YES";else cout<<"NO";
ll MOD;
const double PI = acos(-1.0);

struct segTree {

    struct node {
        vector<int> ordered;
        int cnt;
    };

    vector<node> values;
    int size;
    node emptyNode;

    void merge(node &curr, node &left, node &right) {

        curr.ordered.clear();
        curr.cnt = left.cnt + right.cnt;
        vi l_arr = left.ordered, r_arr = right.ordered;

        int l_ind{}, r_ind{};
        while (l_ind < l_arr.size() || r_ind < r_arr.size()) {
            int inc = l_arr.size() - l_ind;

            if (l_ind < l_arr.size() && r_ind < r_arr.size()) {
                if (r_arr[r_ind] < l_arr[l_ind]) {
                    curr.ordered.push_back(r_arr[r_ind]);
                    r_ind++;
                    curr.cnt += inc;
                } else {
                    curr.ordered.push_back(l_arr[l_ind]);
                    l_ind++;
                }
            } else if (l_ind < l_arr.size()) {
                curr.ordered.push_back(l_arr[l_ind]);
                l_ind++;
            } else {
                curr.ordered.push_back(r_arr[r_ind]);
                r_ind++;
            }
        }
    }


    segTree(ll n) {
        size = 1;
        while (size < n)
            size *= 2;

        emptyNode.ordered = vi();
        emptyNode.cnt = 0;
        values.assign(2 * size, emptyNode);
    }


    void build(vector<int> &arr) {
        build(arr, 0, 0, size - 1);
    }


    void set(int i, int &v) {
        set(i, v, 0, 0, size - 1);
    }

    int calc(ll l, ll r) {
        return calc(l, r, 0, 0, size - 1).cnt;
    }

private:

    void build(vector<int> &arr, ll ind, ll lx, ll rx) {
        if (lx == rx) {
            if (lx < arr.size()) {
                values[ind].ordered.push_back(arr[lx]);
            }
            return;
        }

        ll m = (lx + rx) / 2;
        build(arr, 2 * ind + 1, lx, m);
        build(arr, 2 * ind + 2, m + 1, rx);

        merge(values[ind], values[2 * ind + 1], values[2 * ind + 2]);
    }

    void set(int i, int &v, ll ind, ll lx, ll rx) {
        if (lx == rx) {
            values[ind].ordered[0] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i <= m)
            set(i, v, 2 * ind + 1, lx, m);
        else
            set(i, v, 2 * ind + 2, m + 1, rx);

        merge(values[ind], values[2 * ind + 1], values[2 * ind + 2]);

    }

    node calc(ll l, ll r, ll ind, ll lx, ll rx) {
        if (r < lx || rx < l) {
            return emptyNode;
        }
        if (l <= lx && rx <= r) {
            return values[ind];
        }
        ll m = (lx + rx) / 2;

        node m1, m2;
        m1 = calc(l, r, 2 * ind + 1, lx, m);
        m2 = calc(l, r, 2 * ind + 2, m + 1, rx);

        if (m1.ordered.empty())
            return m2;
        else if (m2.ordered.empty())
            return m1;

        node newNode = emptyNode;
        merge(newNode, m1, m2);
        return newNode;
    }

};


void solveB(){

    ll n , d;
    cin>>n>>d;

    set<int> s;
    s.insert(1);
    if(d == 0 || d == 5)
        s.insert(5);

    if(n>=3 || d == 7)
        s.insert(7);

    int cnt = 0;
    while(d%3 == 0){
        cnt++;
        d/=3;
    }
    if(n > 2)
        cnt++;
    if(n > 5)
        cnt++;

    if(cnt)
        s.insert(3);
    if(cnt > 1)
        s.insert(9);



    veclp(s)
        cout<<*it<<" ";
}

void YallaSolve() {
    solveB();
}


void LotsOfTests() {
    int t;
    cin >> t;
    lp(i, 1, t) {
        YallaSolve();
        cout << "\n";
    }
}

void PLAY() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main() {
    PLAY();
    LotsOfTests();
    //                YallaSolve();
    //            solveA();
}