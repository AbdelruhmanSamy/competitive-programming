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


void YallaSolve() {
    ll n , k;
    cin>>n>>k;
    vll a(n) , h(n);
    for(auto &i:a)cin>>i;
    for(auto &j:h)cin>>j;

    ll st=0 , end  = 1;
    ll ans=0 , sum = a[0];

    while(st!=end || end!=n){
        if(sum <= k)
            ans = max(ans , end - st);

        if(end == n || sum > k){
            sum -= a[st];
            st++;
        }
        else{
            if(h[end-1]%h[end] == 0){
                sum+=a[end];
                end++;
            }
            else{
                st = end;
                sum = a[end];
                end++;
            }
        }
    }
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
    while (true) {
        stringstream ss(s);
        YallaSolve();
        getline(cin, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    //YallaSolve();
    LotsOfTests();
    //uvaLotsOfTests();
    //uvaLotsOfTests2();
}