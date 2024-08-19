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
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18
const ll MOD =  1e9 + 7;
const double PI = acos(-1.0);

void solveC(){
    ll n;
    cin>>n;

    vll arr(n);
    scn(arr);

    ll k;
    cin>>k;

    string s;
    while(k--){
        unordered_map<char , ll>m;
        unordered_map<ll , char>m2;
        cin>>s;

        if(s.size()!=n){
            cout<<"NO\n";
            continue;
        }

        bool f=1;
        lp(i , 0 , s.size()-1){
            if(m.find(s[i])==m.end() && m2.find(arr[i])==m2.end()) {
                m[s[i]] = arr[i];
                m2[arr[i]] = s[i];
            }
            else if(m.find(s[i])==m.end() && m2.find(arr[i]) != m2.end() || m.find(s[i])!=m.end() && m2.find(arr[i])==m2.end() || m[s[i]]!=arr[i] || m2[arr[i]]!=s[i]){
                cout<<"NO\n";
                f=0;
                break;
            }
        }

        if(f)
            cout<<"YES\n";
    }
}


void YallaSolve() {
    solveC();
}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
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
}
