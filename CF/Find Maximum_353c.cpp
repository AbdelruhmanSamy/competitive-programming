//
// Created by abdelruhman on 6/27/24.
//
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
#define MAX 1e9
#define rep(i ,v) for(int i =0 ; i<v.size() ; i++)

void YallaSolve() {
    ll n;
    cin>>n;

    vll arr(n);
    for(auto& i:arr)cin>>i;

    string s;
    cin>>s;

    vll pre(n+1);

    lp(i , 0 , n-1) {
        pre[i + 1] = pre[i]+arr[i];
    }

    ll ans=0 , presum=0;
    for(int i = n-1; i>=0 ; i--){
        if(s[i]=='1'){
            ans=max(ans , presum+pre[i]);
            presum+=arr[i];
        }
    }

    cout<<max(ans , presum);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}

