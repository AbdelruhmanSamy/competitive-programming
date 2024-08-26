#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i <= n; i++)
#define vi vector<int>
#define popcnt(a) __builtin_popcount(a)
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define veclp(n) for(auto it=n.begin() ; it!=n.end();it++)
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18
const ll MOD =  1e9 + 7;
const double PI = acos(-1.0);

void solveC()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (auto &i: a)
        cin >> i;
    sort(all(a), greater<ll>());
    ll A = 0, B = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i&1)
        {
            ll x = min(a[i-1] - a[i], k);
            k -= x;
            B += a[i] + x;
        }
        else
        {
            A += a[i];
        }
    }

    cout<<A-B;
}

void YallaSolve() {
    solveC  ();
}

void LotsOfTests() {

    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
        cout << "\n";
    }
}
void PLAY() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    PLAY();
    LotsOfTests();
}