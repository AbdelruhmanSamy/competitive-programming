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

ll solve(ll val , vi& v){
    ll sz = v.size()-1;
    ll ans = 0;
    veclp(v){
        ans+=*it * pow(val ,  sz);
        sz--;
    }
    return ans;
}

void YallaSolve() {

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
    ll n, m;
    cin >> n >> m;
    while (n && m) {
//        YallaSolve(n, m);
        cin >> n >> m;
    }
}

void uvaLotsOfTests2() {
    string s;
    getline(cin, s);

    while (s != "") {
        vi v;
        stringstream ss(s);
        int n;
        while(!ss.eof()){
            ss >> n;
            v.push_back(n);
        }
        getline(cin, s);
        stringstream st(s);
        bool f = 0;
        while(!st.eof()){
            if(f)
                cout<<" ";
            f = 1;
            st>>n;
            cout<< solve(n , v) ;
        }
        cout << "\n";
        getline(cin, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    //YallaSolve();
    //LotsOfTests();
    //uvaLotsOfTests();
    uvaLotsOfTests2();
}
