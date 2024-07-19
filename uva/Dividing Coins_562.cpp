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
int m;
vvll memo;
vll arr;
ll tot;

ll dp(int i , ll curr){
    if(i == m){
        return abs(curr - (tot-curr));
    }

    if(memo[i][curr]!=-1)
        return memo[i][curr];

    return memo[i][curr] = min(dp(i+1 , curr),dp(i+1 , curr+arr[i]));
}

void YallaSolve() {
  cin>>m;
  if(!m){
      cout<<0;
      return;
  }

  memo.resize(m, vll(50000 , -1));
  tot = 0;
  arr.resize(m);

  for(auto &i:arr) {
      cin >> i;
      tot+=i;
  }

  cout<<dp(0 , 0);
  arr.clear();
  memo.clear();

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
