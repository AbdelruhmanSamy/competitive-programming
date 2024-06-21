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
#define rep(i ,v) for(int i =0 ; i<v.size() ; i++)


void YallaSolve() {
    int n;
    cin>>n;

    vi s(n);
    for(auto& i : s) cin>>i;

    vi fact;
    fact.push_back(n);
    for(int i = 2 ; i*i<=n ; i++){
        if(n%i == 0){
            if(n/i != 2)
                fact.push_back(n/i);
            if(i!=2)
                fact.push_back(i);
        }
    }

    rep(i , fact){
        lp(k , 0 , (n/fact[i])-1){
            lp(j , 0 , fact[i]-1){
                if(!s[(k + j*(n/fact[i]))%n])
                    break;
                if(j == fact[i]-1){
                    cout<<"YES";
                    return;
                }
            }
        }
    }
    cout<<"NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();;
}