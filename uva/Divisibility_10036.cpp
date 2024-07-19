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
#define pi 3.141592654
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define oo 1e18

vll arr;
ll n , k;
ll memo[10000][100];

bool dp(int i , ll curr){
    if(i == n){
        if(curr%k)
            return 0;
        return 1;
    }

    ll &ret = memo[i][curr];

    if(ret!=-1)
        return ret;

    return ret = dp(i+1 , (curr+arr[i])%k) || dp(i+1 , (curr-arr[i])%k);

}


void YallaSolve() {
    cin>>n>>k;
    arr.resize(n);
    memset(memo , -1 , sizeof(memo));
    for(auto &i : arr)cin>>i;

    if(dp(1 , arr[0]%k))
        cout<<"Divisible";
    else
        cout<<"Not divisible";

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
//        YallaSolve();
}
