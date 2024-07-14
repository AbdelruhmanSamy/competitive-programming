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

vi prime(MAX , 1);
void sieve(){
    prime[1] = 0;

    for(int i = 2 ; i*i<=MAX ; i++){
        if(prime[i]){
            for(int j = i*i ; j<=MAX ; j+=i){
                prime[j] = 0;
            }
        }
    }

};

void YallaSolve(){
    ll n , k;
    cin>>n>>k;

    ll val = 0;
    ll val1 = 0;
    vll arr(k);

    lp(i , 0 , k-1){
        cin>>arr[i];

        if(arr[i]>val1)
            val1 = arr[i];

        val += (2*arr[i]-1);
    }


    ll ans;
    if(!val1) {
        ans = val - 1 ;
    }
    else
        ans = val - (2*val1 -1);


    cout<<ans;
}
void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
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
    LotsOfTests();
//        YallaSolve();
}