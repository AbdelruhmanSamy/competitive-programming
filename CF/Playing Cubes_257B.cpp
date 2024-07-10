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
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)


void YallaSolve(){
    int n , m;
    int a , b;
    cin>>n>>m;
    a = min(n , m);
    b = max(n , m);

    cout<<fixed<<setprecision(0);

    int p=0 , v =a;
    bool f=0;
    if(a%2){
        a--;
    }
    else {
        b--;
        if(b>=a)
            f=1;
    }

    m = min(a , b);
    n = max(a , b);

    if(m%2)
        m--;

    int val = m/2;
    p+=max(0 , val);

    if(!f) {
        p += max(0, val);
        n-=max(0 , val)*2;
    }
    else {
        p+=max(0, val-1);
        n-=max(0 ,(val-1))*2;
    }
    p+=max(0, n-1);
    cout<<p<<" "<< v;
}
void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
//            YallaSolve();
        cout << "\n";
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
//        LotsOfTests();
    YallaSolve();
}
