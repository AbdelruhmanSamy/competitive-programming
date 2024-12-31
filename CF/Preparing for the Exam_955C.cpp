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

void solveC() {
    ll n, m, k;
    cin>>n>>m>>k;

    vll list(m) , q(k);
    scn(list); scn(q);

    if(k < n-1)
        cout<< string(m , '0');
    else if(k == n){
        cout<<string(m , '1');
    }
    else{
        map<ll , bool> canAnswer;
        lp(i , 0,  k-1){
            canAnswer[q[i]] = 1;
        }

        lp(i, 0 ,  m-1){
            if(!canAnswer[list[i]])
                cout<<1;
            else
                cout<<0;
        }
    }
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
}