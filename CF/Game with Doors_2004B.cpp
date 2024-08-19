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

void solveB(){
    ll l1  ,r1;
    ll l2 , r2;

    cin>>l1 >>r1>>l2>>r2;


    if(l1>r2 || l2>r1)
        cout<<1;

    else{
        ll l , r;
        l = max(l1 , l2);
        if(l1!=l2)
            l--;
        r = min(r1 , r2);
        if(r1!=r2)
            r++;
        cout<<r-l;
    }

}

void YallaSolve() {
    solveB();
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
