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

string a, b;
vvi memo(101 , vi(101 , -1));

int dp(int i , int j){
    if(memo[i][j]!=-1)
        return memo[i][j];

    if(i == a.size() || j== b.size())
        return memo[i][j] = 0;

    if(a[i] == b[j])
        return memo[i][j] = 1 + dp(i+1 , j+1);

    int ans1 , ans2;
    ans1 = dp(i , j+1);
    ans2 = dp(i+1 , j);

    return memo[i][j] = max(ans1 , ans2);
}

void YallaSolve() {
    int ind = 1;
    while(true){
        getline(cin , a);
        if(a[0] == '#')
            return;
        getline(cin , b);
        cout<<"Case #"<<ind++<<": you can visit at most "<<dp(0 , 0)<<" cities."<<"\n";
        memo.clear();
        memo.resize(101 , vi(101 , -1));
    }

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
//      LotsOfTests();
    YallaSolve();
}
