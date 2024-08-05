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
#define scn(v) for (auto& i : v)cin >> i;

#define oo 1e18
const int MOD = (int) 1e9 + 7;
const double PI = acos(-1.0);


void solveA(){
    ll n;
    cin>>n;

    string s;
    cin>>s;

    map<char , ll>m;
    ll ans=0;
    lp(i , 0 , 4*n-1){
        if(s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ||s[i] == 'D' ){
            if(m[s[i]] < n) {
                m[s[i]]++;
                ans++;
            }
        }
    }

    cout<<ans;
}

void solveB(){
    ll n;
    cin>>n;

    vll arr(n);
    scn(arr);

    sort(all(arr));

    bool f = 0;
    ll lrgOdd;

    vll vec;
    lp(i , 0 , n-1){
        if(arr[i]&1){
            lrgOdd = arr[i];
            f=1;
        }
        else
            vec.push_back(arr[i]);
    }

    if(!f){
        cout<<0;
        return;
    }

    ll ans = 0;
    ll lstInd = n;
    if(vec.size()){

        lp(i , 0  , vec.size()-1){
            if(vec[i] <= lrgOdd){
                ans++;
                lrgOdd+=vec[i];
            }
            else {
                lstInd = i;
                break;
            }
        }

        for(int i = vec.size()-1 ; i>= lstInd ; i--){
            if(vec[i] <= lrgOdd){
                ans++;
                lrgOdd+=vec[i];
            }
            else{
                ans+=2;
                lrgOdd+= 2*vec[i];
            }
        }
    }

    cout<<ans;

}


void YallaSolve() {
    solveB();
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
//       YallaSolve();
}