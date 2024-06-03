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
#define MAX 100000

void YallaSolve() {
    int n , k;
    cin>>n>>k;
    set<pair<ll,ll>> s;
    lp(i , 0  ,n-1){
        ll val;
        cin>>val;
        s.insert({val , i+1});
    }

    int ans=0;
    vector<pair<ll , ll>>out;

    auto it = s.begin();
    auto it2 = prev(s.end());
    while(it->first+1< it2->first && k){
        ans++;
        auto v1 = *it;
        auto v2 = *it2;
        s.erase(it);
        s.erase(it2);

        s.insert({v1.first+1 , v1.second});
        s.insert({v2.first -1 , v2.second});

        out.push_back({v2.second , v1.second});

        it = s.begin();
        it2 = prev(s.end());
        k--;
    }

    cout<< it2->first-it->first<< " "<< ans<<"\n";
    veclp(out){
        cout<<it->first<<" "<<it->second;
        cout<<"\n";
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

void uvaLotsOfTests() {
    ll n , m;
    cin>>n>>m;
    while (n&&m) {
        //        YallaSolve(n, m);
        cin>>n>>m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
    //LotsOfTests();
    //uvaLotsOfTests();
}

