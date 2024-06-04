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


void YallaSolve(int n , int m) {
    cout<<(n^m);
}

void LotsOfTests() {
    int t;
    cin>>t;
    while (t--) {
//                YallaSolve();
        cout << "\n";
    }
}

void uvaLotsOfTests() {
    ll n , m;
    cin>>n>>m;
    while (n&&m) {
        YallaSolve(n, m);
        cin>>n>>m;
    }
}

void uvaLotsOfTests2(){
    string s;
    getline(cin ,s);
    while(s!=""){
        stringstream ss(s);
        int n , m;
        ss>>n>>m;
        YallaSolve(n , m);
        cout<<"\n";
        getline(cin ,s);

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



