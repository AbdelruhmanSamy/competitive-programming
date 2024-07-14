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
    ll n,  m , k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    s = 'S' + s + 'S';
    vll logs , water;
    lp(i , 0 , s.size()-1){
        if(s[i] == 'L' || s[i] == 'S')
            logs.push_back(i);
    }

    bool f = 1;
    int curr;
    lp(i , 1 , logs.size()-1){
        if(logs[i] - logs[i-1] > m){
            int curr = logs[i-1]+m;
            lp(j , curr , logs[i]-1){
                k--;
                if (s[j] == 'C' || k < 0) {
                    f = 0;
                    break;
                }
            }
            if(!f)
                break;
        }
    }

    if(f)
        cout<<"YES";
    else
        cout<<"NO";
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
