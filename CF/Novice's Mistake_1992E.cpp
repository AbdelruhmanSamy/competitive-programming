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

int n;
void binary_search(int l , int r, int val , int sz, vector<pii>& ans){
    int mid = (r-l)/2 + l;
    int a  , b;
    a = mid; b = (mid*(floor(log10(n))+1)- sz);
    if(n*a - b == val && b>0 && b<= 1e4) {
        ans.push_back(mp(a, b));
        return;
    }
    else if(l>=r)
        return;
    else if(n*a - b < val)
        return binary_search(mid+1 , r , val , sz , ans);

    return binary_search(l , mid, val , sz , ans);
}

void YallaSolve(){
    cin>>n;
    vector<pii> ans;
    int val = n;

    if(n == 1){
        lp(i , 2 , 10000){
            ans.push_back(mp(i , i-1));
        }
        val = 11;
    }

    int a , b , ind = 0;
    string s = to_string(val);
    string g = s;
    int curr = s.size();
    while(val<=99e4){
        binary_search(1  , 1e4 , val , curr , ans);
        curr++;
        g = g + s[ind%s.size()];
        ind++;
        val= stoi(g);
    }

    cout<<ans.size()<<"\n";
    veclp(ans){
        cout<<it->first<<" "<<it->second<<"\n";
    }
}
void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
//            cout << "\n";
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