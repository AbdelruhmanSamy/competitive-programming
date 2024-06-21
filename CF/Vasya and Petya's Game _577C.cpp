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


vi sieve(int n){
    vi primes(n+2 , 1);

    for(int i = 2 ; i*i<=n ; i++){
        for(int j = i*i ; j<= n ; j+=i){
            primes[j] = 0;
        }
    }
    return primes;
}

void YallaSolve() {
    ll n;
    cin>>n;

    vll ans;
    vi primes = sieve(n);

    lp(i , 2 ,n){
        if(!primes[i])
            continue;

        ans.push_back(i);
        ll val = i*i;
        while(val <=n){
            ans.push_back(val);
            val*=i;
        }
    }

    cout<<ans.size()<<"\n";
    veclp(ans) cout<<*it<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}