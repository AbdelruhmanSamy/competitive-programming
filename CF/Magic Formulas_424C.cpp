//
// Created by abdelruhman on 6/25/24.
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
    ll ans = 0;
    vll xor_val(n+1);

    lp(i , 1 , n){
        ll val;
        cin>>val;
        ans^=val;
        xor_val[i] = xor_val[i-1]^i;
    }

    lp(i , 1  , n){
        ll blocks = n/i;
        ll leftover = n%i;

        if(blocks & 1){
            ans ^= xor_val[i-1];
        }

        ans ^= xor_val[leftover];
    }

    cout<<ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}