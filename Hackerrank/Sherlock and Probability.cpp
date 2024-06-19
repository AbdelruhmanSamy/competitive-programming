//
// Created by abdelruhman on 6/19/24.
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
#define MAX 5e4


ll gcd(ll a , ll b){
    if(a == 0)
        return b;
    return gcd(b%a , a);
}

string YallaSolve() {
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;
    ll ans = 0;
    vi ind ;
    lp(i, 0 , s.size()-1){
        if(s[i] == '1'){
            ans++;
            ind.push_back(i);
        }
    }

    int st = 0 , end = 1;
    while(end < ind.size()){
        if(ind[end] - ind[st]<=k){
            ans+=2*(end-st);
            end++;
        }
        else
            st++;
        if(st == end)
            end++;
    }

    if(ans == 0)
        return to_string(ans) +"/1";

    ll ans2 = pow(n , 2);
    ll val  = gcd(ans, ans2);
    ans/=val;
    ans2/=val;

    return to_string(ans) + "/" + to_string( ans2);
}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        string s = YallaSolve();
        cout<<s;
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    //YallaSolve();
    LotsOfTests();
}