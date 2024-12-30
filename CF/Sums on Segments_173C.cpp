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

void solveC() {
    ll n;
    cin >> n;

    vll arr(n);
    scn(arr);

    vll preSum(n);

    int ind = n;
    lp(i, 0, n - 1) {
        if (arr[i] != 1 && arr[i] != -1) {
            ind = i;
            break;
        }
    }

    preSum[0] = !ind? 0 :arr[0];
    int j = 1 , prev = 0;
    while(j < n) {
        if(j != ind) {
            preSum[j] = preSum[prev] + arr[j];
            prev = j;
        }
        else{
            preSum[j] = preSum[prev];
        }
        j++;
    }


    ll minPrefL = 0, maxPrefL = 0, minPrefR = 0 , maxPrefR = 0;
    ll minL = INT_MAX, maxL = 0;
    ll minR = INT_MAX, maxR = 0;
    ll minTot = INT_MAX, maxTot = 0;

    lp(i, 0, n - 1) {

        if(i < ind) {
            minPrefL = min(preSum[i], minPrefL);
            maxPrefL = max(preSum[i], maxPrefL);
            minL = min(preSum[i] - maxPrefL, minL);
            maxL = max(preSum[i] - minPrefL, maxL);
        }

        if(i > ind){
            ll val = preSum[i] - preSum[ind];
            minPrefR = min(val, minPrefR);
            maxPrefR = max(val, maxPrefR);
            minR = min(val - maxPrefR, minR);
            maxR = max(val - minPrefR, maxR);
        }
    }

    ll mnl = 0 , mxl = 0, curr = 0;
    for(int i = ind-1 ; i>=0 ; i--){
        curr +=arr[i];
        mnl = min(mnl , curr);
        mxl = max(mxl , curr);
    }


    ll minVal = min({minL, minR , 0LL}) ;
    ll maxVal = max(maxL, maxR);


    ll minAdd = min(mnl + minPrefR , 0LL );
    ll maxAdd = mxl + maxPrefR;

    vll ans;

    if (ind != n && arr[ind] < 0) {
        lp(i, arr[ind] + minAdd, arr[ind] + maxAdd)
            ans.push_back(i);
    }

    ll st = (ind !=n && arr[ind] < 0 )? max(minVal, arr[ind] + maxAdd + 1) : minVal;

    while(st <= maxVal) {
        ans.push_back(st);
        st++;
    }
    if (ind != n && arr[ind] > 0) {
        st = max(arr[ind] + minAdd, maxVal + 1);
        lp(i, st, arr[ind] + maxAdd)ans.push_back(i);
    }

    cout<<ans.size()<<"\n";

    veclp(ans) cout<<*it<<" ";


}

void YallaSolve() {
    solveC();
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