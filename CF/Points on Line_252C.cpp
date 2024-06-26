//
// Created by abdelruhman on 6/26/24.
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

ll ncr(ll n ){
    return (n*(n-1))/2;
}

void YallaSolve() {
    ll n ,d;
    cin>>n>>d;

    vll arr(n);
    for(auto &i : arr)cin>>i;

    ll ans = 0;
    ll pre_j=0;
    lp( i , 0 , n-3){
        int j = lower_bound(all(arr) , arr[i]+d+1) - arr.begin();
        j--;

        if((j-i+1) >=3) {
            ans +=ncr(j - i);
        }
    }

    cout<<ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}