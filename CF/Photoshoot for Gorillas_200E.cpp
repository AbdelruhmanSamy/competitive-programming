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

void solveE(){
    ll n , m , k;
    cin>>n>>m>>k;

    ll w;
    cin>>w;

    vll arr(w);
    scn(arr);
    sort(all(arr), greater<>());

    ll ans = 0;

    vll vec;
    lp(i , 0 , n-1){
        lp(j, 0  , m-1){
            ll x = min({int(i+1) , int(k) , int(n-k+1), int(n-i)});
            ll y = min({int(j+1) , int(k) , int(m-k+1), int(m-j)});

            vec.push_back(x*y);
        }
    }

    sort(all(vec) , greater<>());

    lp(i , 0 , w-1)
        ans+=vec[i]*arr[i];

    cout<<ans;
}

void YallaSolve() {
    solveE();
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
