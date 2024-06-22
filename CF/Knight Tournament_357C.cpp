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
    int n , m;
    cin>>n>>m;

    set<int> s;
    vi ans(n);
    lp(i , 1 , n) s.insert(i);

    lp(i,  0 , m-1){
        int a , b ,  c;
        cin>>a>>b>>c;
        auto it = s.lower_bound(a);
        while(it!=s.end() && *it <= b){
            if(*it == c) {
                it++;
                continue;
            }
            ans[*it - 1] = c;
            auto it2 = it;
            it++;
            s.erase(it2);
        }
    }

    veclp(ans) cout<<*it<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
}