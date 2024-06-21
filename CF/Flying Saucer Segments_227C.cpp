//
// Created by abdelruhman on 6/21/24.
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


ll power(ll k , ll m){
    if(k == 1)
        return 3%m;

    ll val = power(k/2 , m);

    if(k % 2 == 1){
        return  (3%m * val%m * val%m)%m;
    }
    return (val%m * val%m)%m;
}

void YallaSolve() {
    ll n , m;
    cin>>n>>m;
    ll val = power(n , m);

    if(val)
        cout<<(val - 1%m)%m;
    else
        cout<< m-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}